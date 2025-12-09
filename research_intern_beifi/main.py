"""
Autonomous Rover Main Control System

This module implements the main control loop for an autonomous rover using
Intel RealSense camera for depth perception and proportional control for
navigation. The system tracks distance to obstacles and adjusts motor control
accordingly.

Author: Luis Fernando
Institution: Instituto Politécnico Nacional (IPN)
Project: BEIFI Research Internship - Autonomous Rover
Date: 2025
"""

import cv2
import numpy as np
from datetime import datetime
import logging
from typing import Tuple, List
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt

from src.Core.RoverCamera import RoverCamera

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


class JetsonRover:
    """
    Main rover control class implementing autonomous navigation.
    
    This class manages the rover's camera, implements a proportional controller
    for distance-based navigation, and collects telemetry data for analysis.
    
    Attributes:
        camera_rover (RoverCamera): Intel RealSense camera interface
        target_point (Tuple[int, int]): Image coordinates for distance measurement
        setpoint (float): Target distance in meters
        kp_voltage (float): Proportional gain for voltage control
        max_voltage (float): Maximum voltage output
        telemetry (dict): Dictionary storing telemetry data
    """
    
    # Control parameters
    SETPOINT = 0.2  # Target distance in meters
    KP_VOLTAGE = 100  # Proportional gain
    MAX_VOLTAGE = 100  # Maximum voltage
    TARGET_POINT = (320, 240)  # Center of 640x480 frame
    MAX_DISTANCE_JUMP = 10  # Maximum allowed distance change (outlier rejection)
    
    def __init__(self):
        """Initialize the Jetson Rover with camera and telemetry."""
        try:
            self.camera_rover = RoverCamera()
            logger.info("Camera initialized successfully")
        except Exception as e:
            logger.error(f"Failed to initialize camera: {e}")
            raise
        
        self.target_point = self.TARGET_POINT
        self.setpoint = self.SETPOINT
        self.kp_voltage = self.KP_VOLTAGE
        self.max_voltage = self.MAX_VOLTAGE
        
        # Telemetry data
        self.telemetry = {
            'times': [],
            'distances': [],
            'errors': [],
            'voltages': [],
            'velocities': [],
            'directions': []
        }
    
    def calculate_velocity(self, time_elapsed: float) -> float:
        """
        Calculate instantaneous velocity based on distance change.
        
        Args:
            time_elapsed: Time difference in seconds
            
        Returns:
            float: Velocity in m/s
        """
        if len(self.telemetry['distances']) < 2 or time_elapsed == 0:
            return 0.0
        
        distance_change = (
            self.telemetry['distances'][-2] - 
            self.telemetry['distances'][-1]
        )
        return distance_change / time_elapsed
    
    def calculate_voltage(self, error: float) -> float:
        """
        Calculate control voltage based on error (proportional control).
        
        Args:
            error: Distance error in meters (current - setpoint)
            
        Returns:
            float: Control voltage limited to max_voltage
        """
        voltage = self.kp_voltage * error
        
        # Limit voltage to maximum
        if abs(voltage) >= self.max_voltage:
            return self.max_voltage if voltage > 0 else -self.max_voltage
        
        return voltage
    
    def calculate_direction(self, error: float) -> Tuple[int, int]:
        """
        Determine motor direction based on error.
        
        Args:
            error: Distance error in meters
            
        Returns:
            Tuple[int, int]: (forward, reverse) direction flags
        """
        if error > 0:
            return (1, 0)  # Forward
        elif error < 0:
            return (0, 1)  # Reverse
        else:
            return (0, 0)  # Stop
    
    def draw_telemetry(
        self,
        bgr_frame: np.ndarray,
        depth_colormap: np.ndarray,
        distance: float,
        velocity: float,
        time_elapsed: float,
        direction: Tuple[int, int]
    ) -> None:
        """
        Draw telemetry information on video frames.
        
        Args:
            bgr_frame: Color image frame
            depth_colormap: Colorized depth frame
            distance: Current distance in meters
            velocity: Current velocity in m/s
            time_elapsed: Total elapsed time in seconds
            direction: Current direction tuple
        """
        # Draw target point
        cv2.circle(
            bgr_frame, 
            self.target_point, 
            2, 
            (0, 255, 0), 
            2
        )
        cv2.circle(
            depth_colormap, 
            self.target_point, 
            2, 
            (0, 255, 0), 
            2
        )
        
        # Distance text
        cv2.putText(
            bgr_frame,
            f"{distance:.3f}m",
            (self.target_point[0], self.target_point[1] - 10),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.6,
            (0, 255, 0),
            2
        )
        cv2.putText(
            depth_colormap,
            f"{distance:.3f}m",
            (self.target_point[0], self.target_point[1] - 10),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.6,
            (0, 255, 0),
            2
        )
        
        # Direction text
        direction_text = "Forward" if direction[0] == 1 else (
            "Reverse" if direction[1] == 1 else "Stop"
        )
        
        # Overlay text
        cv2.putText(
            bgr_frame,
            f"Velocity: {abs(velocity) * 10:.3f} m/s",
            (self.target_point[0] - 50, self.target_point[1] + 40),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.5,
            (0, 255, 0),
            2
        )
        cv2.putText(
            bgr_frame,
            f"Time: {time_elapsed:.3f}s",
            (20, 30),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.6,
            (0, 255, 0),
            2
        )
        cv2.putText(
            bgr_frame,
            f"Direction: {direction_text}",
            (300, 30),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.6,
            (0, 255, 0),
            2
        )
    
    def run(self) -> None:
        """
        Main control loop for the rover.
        
        Continuously captures frames, measures distance, calculates control
        outputs, and displays telemetry. Press ESC to exit.
        """
        logger.info("Starting rover control loop...")
        logger.info(f"Target distance (setpoint): {self.setpoint}m")
        logger.info("Press ESC to stop")
        
        time_elapsed = 0.0
        
        # Initialize telemetry with zero values
        self.telemetry['times'].append(0)
        self.telemetry['distances'].append(0)
        self.telemetry['errors'].append(0)
        self.telemetry['voltages'].append(0)
        self.telemetry['velocities'].append(0)
        
        try:
            while True:
                t1 = datetime.now()
                
                # Get frames from camera
                success, depth_frame, depth_image, color_image, depth_colormap = (
                    self.camera_rover.get_frames()
                )
                
                if not success:
                    logger.error("Failed to capture frames. Check camera connection.")
                    break
                
                # Measure distance at target point
                distance = depth_frame.get_distance(
                    self.target_point[0], 
                    self.target_point[1]
                )
                
                # Reject outliers (sudden large jumps in distance)
                if (len(self.telemetry['distances']) > 0 and 
                    abs(self.telemetry['distances'][-1] - distance) > 
                    self.MAX_DISTANCE_JUMP):
                    distance = self.telemetry['distances'][-1]
                
                # Calculate error and control outputs
                error = distance - self.setpoint
                voltage = self.calculate_voltage(error)
                direction = self.calculate_direction(error)
                
                # Update timing
                t2 = datetime.now()
                time_diff = (t2 - t1).total_seconds()
                time_elapsed += time_diff
                
                # Calculate velocity
                velocity = self.calculate_velocity(time_diff)
                
                # Store telemetry
                self.telemetry['times'].append(time_elapsed)
                self.telemetry['distances'].append(distance)
                self.telemetry['errors'].append(error)
                self.telemetry['voltages'].append(voltage)
                self.telemetry['velocities'].append(velocity)
                self.telemetry['directions'].append(direction[0])
                
                # Draw telemetry on frames
                self.draw_telemetry(
                    color_image,
                    depth_colormap,
                    distance,
                    velocity,
                    time_elapsed,
                    direction
                )
                
                # Display frames
                cv2.imshow("Rover Color View", color_image)
                # Uncomment to show depth colormap
                # cv2.imshow("Rover Depth View", depth_colormap)
                
                # Check for ESC key
                key = cv2.waitKey(1)
                if key == 27:  # ESC
                    logger.info("ESC pressed. Stopping rover...")
                    break
                    
        except KeyboardInterrupt:
            logger.info("Interrupted by user")
        except Exception as e:
            logger.error(f"Error in control loop: {e}")
        finally:
            cv2.destroyAllWindows()
            self.camera_rover.release()
            logger.info("Rover stopped")
    
    def show_results(self) -> None:
        """
        Display telemetry results in a 4-panel plot.
        
        Shows distance, error, velocity, and voltage over time.
        """
        logger.info("Generating telemetry plots...")
        
        # Print statistics
        print(f"\nTelemetry Statistics:")
        print(f"  Duration: {self.telemetry['times'][-1]:.2f}s")
        print(f"  Data points: {len(self.telemetry['times'])}")
        print(f"  Avg distance: {np.mean(self.telemetry['distances']):.3f}m")
        print(f"  Avg error: {np.mean(self.telemetry['errors']):.3f}m")
        
        # Create figure with subplots
        fig = plt.figure(figsize=(16, 9))
        fig.suptitle(
            'Autonomous Rover Telemetry Analysis', 
            fontsize=16, 
            fontweight='bold'
        )
        
        # Distance plot
        ax1 = fig.add_subplot(2, 2, 1)
        ax1.plot(self.telemetry['times'], self.telemetry['distances'], 'b-', linewidth=2)
        ax1.axhline(y=self.setpoint, color='r', linestyle='--', label='Setpoint')
        ax1.set_xlabel('Time [s]')
        ax1.set_ylabel('Distance [m]')
        ax1.set_title('Distance vs Time')
        ax1.grid(True, alpha=0.3)
        ax1.legend()
        
        # Error plot
        ax2 = fig.add_subplot(2, 2, 2)
        ax2.plot(self.telemetry['times'], self.telemetry['errors'], 'r-', linewidth=2)
        ax2.axhline(y=0, color='k', linestyle='--', alpha=0.5)
        ax2.set_xlabel('Time [s]')
        ax2.set_ylabel('Error [m]')
        ax2.set_title('Error vs Time')
        ax2.grid(True, alpha=0.3)
        
        # Velocity plot
        ax3 = fig.add_subplot(2, 2, 3)
        ax3.plot(self.telemetry['times'], self.telemetry['velocities'], 'g-', linewidth=2)
        ax3.set_xlabel('Time [s]')
        ax3.set_ylabel('Velocity [m/s]')
        ax3.set_title('Velocity vs Time')
        ax3.grid(True, alpha=0.3)
        
        # Voltage plot
        ax4 = fig.add_subplot(2, 2, 4)
        ax4.plot(self.telemetry['times'], self.telemetry['voltages'], 'orange', marker='o', markersize=2)
        ax4.set_xlabel('Time [s]')
        ax4.set_ylabel('Control Voltage [V]')
        ax4.set_title('Control Voltage vs Time')
        ax4.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.show()
        
        logger.info("Telemetry display complete")


def main():
    """
    Main entry point for the autonomous rover system.
    
    Initializes the rover, runs the control loop, and displays results.
    """
    print("=" * 60)
    print("Autonomous Rover Control System")
    print("Instituto Politécnico Nacional (IPN)")
    print("BEIFI Research Internship")
    print("=" * 60)
    print()
    
    try:
        rover = JetsonRover()
        rover.run()
        
        # Show telemetry after run
        if len(rover.telemetry['times']) > 1:
            rover.show_results()
        else:
            logger.warning("Insufficient data collected for analysis")
            
    except Exception as e:
        logger.error(f"Fatal error: {e}")
        return 1
    
    return 0


if __name__ == "__main__":
    exit(main())
