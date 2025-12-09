"""
RoverCamera Module

This module provides an interface to interact with Intel RealSense cameras
for the autonomous rover project. It handles depth and color frame acquisition.

Author: Luis Fernando
Institution: Instituto Politécnico Nacional (IPN)
Project: BEIFI Research Internship - Autonomous Rover
"""

import pyrealsense2 as rs
import numpy as np
from typing import Tuple, Optional
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


class RoverCamera:
    """
    Interface class for Intel RealSense camera operations.
    
    This class manages the RealSense camera pipeline, including configuration,
    frame acquisition, and proper resource cleanup.
    
    Attributes:
        pipeline (rs.pipeline): RealSense pipeline for streaming
        config (rs.config): Configuration for camera streams
        width (int): Frame width in pixels (default: 640)
        height (int): Frame height in pixels (default: 480)
        fps (int): Frames per second (default: 30)
    """
    
    def __init__(
        self, 
        width: int = 640, 
        height: int = 480, 
        fps: int = 30
    ) -> None:
        """
        Initialize RoverCamera with Intel RealSense camera.
        
        Args:
            width: Frame width in pixels (default: 640)
            height: Frame height in pixels (default: 480)
            fps: Frames per second (default: 30)
            
        Raises:
            RuntimeError: If camera initialization fails
        """
        self.width = width
        self.height = height
        self.fps = fps
        self.pipeline = None
        self.config = None
        
        try:
            self._initialize_camera()
            logger.info(
                f"RoverCamera initialized: {width}x{height} @ {fps}fps"
            )
        except Exception as e:
            logger.error(f"Failed to initialize camera: {e}")
            raise RuntimeError(f"Camera initialization failed: {e}")
    
    def _initialize_camera(self) -> None:
        """
        Configure and start the RealSense camera pipeline.
        
        This method configures both depth and color streams with the
        specified resolution and frame rate.
        """
        # Configure depth and color streams
        self.pipeline = rs.pipeline()
        self.config = rs.config()

        # Get device product line for setting a supporting resolution
        pipeline_wrapper = rs.pipeline_wrapper(self.pipeline)
        pipeline_profile = self.config.resolve(pipeline_wrapper)
        device = pipeline_profile.get_device()
        device_product_line = str(
            device.get_info(rs.camera_info.product_line)
        )
        
        logger.info(f"Device product line: {device_product_line}")

        # Enable streams
        self.config.enable_stream(
            rs.stream.depth, 
            self.width, 
            self.height, 
            rs.format.z16, 
            self.fps
        )
        self.config.enable_stream(
            rs.stream.color, 
            self.width, 
            self.height, 
            rs.format.bgr8, 
            self.fps
        )

        # Start streaming
        self.pipeline.start(self.config)

    def get_frames(self) -> Tuple[
        bool, 
        Optional[rs.depth_frame], 
        Optional[np.ndarray], 
        Optional[np.ndarray], 
        Optional[np.ndarray]
    ]:
        """
        Capture and return depth and color frames from the camera.
        
        Returns:
            A tuple containing:
                - success (bool): True if frames were captured successfully
                - depth_frame (rs.depth_frame): Raw depth frame object
                - depth_image (np.ndarray): Depth data as numpy array
                - color_image (np.ndarray): BGR color image as numpy array
                - depth_colormap (np.ndarray): Colorized depth visualization
                
        Example:
            >>> camera = RoverCamera()
            >>> success, depth_frame, depth_img, color_img, colormap = camera.get_frames()
            >>> if success:
            >>>     distance = depth_frame.get_distance(320, 240)
        """
        try:
            # Wait for a coherent pair of frames: depth and color
            frames = self.pipeline.wait_for_frames()

            depth_frame = frames.get_depth_frame()
            color_frame = frames.get_color_frame()
            
            # Check if frames are valid
            if not depth_frame or not color_frame:
                logger.warning("Invalid frame received")
                return False, None, None, None, None

            # Create colormap to show the depth of the objects
            colorizer = rs.colorizer()
            depth_colormap = np.asanyarray(
                colorizer.colorize(depth_frame).get_data()
            )

            # Convert to numpy arrays
            depth_image = np.asanyarray(depth_frame.get_data())
            color_image = np.asanyarray(color_frame.get_data())
            
            return True, depth_frame, depth_image, color_image, depth_colormap
            
        except Exception as e:
            logger.error(f"Error capturing frames: {e}")
            return False, None, None, None, None

    def release(self) -> None:
        """
        Stop the camera pipeline and release resources.
        
        This method should be called when the camera is no longer needed
        to properly cleanup resources.
        """
        try:
            if self.pipeline:
                self.pipeline.stop()
                logger.info("Camera pipeline stopped successfully")
        except Exception as e:
            logger.error(f"Error stopping camera pipeline: {e}")
    
    def __enter__(self):
        """Context manager entry."""
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """Context manager exit with automatic cleanup."""
        self.release()
        return False
