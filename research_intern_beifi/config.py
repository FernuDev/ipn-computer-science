"""
Configuration Module

Central configuration file for the autonomous rover system.
All configurable parameters should be defined here.

Author: Luis Fernando
Institution: Instituto Politécnico Nacional (IPN)
"""

# =============================================================================
# Camera Configuration
# =============================================================================

CAMERA_CONFIG = {
    'width': 640,           # Frame width in pixels
    'height': 480,          # Frame height in pixels
    'fps': 30,              # Frames per second
    'depth_format': 'z16',  # Depth format
    'color_format': 'bgr8', # Color format
}

# =============================================================================
# Control System Configuration
# =============================================================================

CONTROL_CONFIG = {
    'setpoint': 0.2,           # Target distance in meters
    'kp_voltage': 100,         # Proportional gain
    'max_voltage': 100,        # Maximum voltage output
    'target_point': (320, 240), # Center point for distance measurement
    'max_distance_jump': 10,   # Max allowed distance change (outlier rejection)
}

# =============================================================================
# Network Configuration
# =============================================================================

NETWORK_CONFIG = {
    'server_host': '',          # Empty for all interfaces
    'server_port': 8485,        # Server port
    'client_host': '10.104.65.191',  # Rover IP address
    'client_port': 8485,        # Client port
    'max_clients': 10,          # Maximum concurrent clients
    'buffer_size': 2048,        # Socket buffer size
}

# =============================================================================
# Logging Configuration
# =============================================================================

LOGGING_CONFIG = {
    'level': 'INFO',            # Logging level: DEBUG, INFO, WARNING, ERROR
    'format': '%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    'date_format': '%Y-%m-%d %H:%M:%S',
}

# =============================================================================
# Display Configuration
# =============================================================================

DISPLAY_CONFIG = {
    'show_color_frame': True,   # Show color camera view
    'show_depth_frame': False,  # Show depth colormap
    'window_name_color': 'Rover Color View',
    'window_name_depth': 'Rover Depth View',
    'telemetry_color': (0, 255, 0),  # Green (BGR)
    'font': 'FONT_HERSHEY_SIMPLEX',
    'font_scale': 0.6,
    'font_thickness': 2,
}

# =============================================================================
# Telemetry Configuration
# =============================================================================

TELEMETRY_CONFIG = {
    'plot_width': 16,           # Plot width in inches
    'plot_height': 9,           # Plot height in inches
    'plot_dpi': 100,            # Plot DPI
    'save_data': False,         # Save telemetry data to file
    'data_file': 'telemetry_data.csv',
}

# =============================================================================
# Motor Configuration (Arduino)
# =============================================================================

MOTOR_CONFIG = {
    'serial_port': '/dev/ttyUSB0',  # Serial port for Arduino
    'baud_rate': 9600,              # Serial baud rate
    'timeout': 1.0,                 # Serial timeout in seconds
    'pwm_frequency': 1000,          # PWM frequency in Hz
}

# =============================================================================
# Safety Configuration
# =============================================================================

SAFETY_CONFIG = {
    'min_distance': 0.1,        # Minimum safe distance in meters
    'max_distance': 5.0,        # Maximum detection distance in meters
    'emergency_stop_distance': 0.05,  # Emergency stop distance
    'watchdog_timeout': 5.0,    # Watchdog timeout in seconds
}

# =============================================================================
# Development Configuration
# =============================================================================

DEV_CONFIG = {
    'debug_mode': False,        # Enable debug mode
    'simulate_hardware': False, # Simulate hardware (no real camera/motors)
    'verbose_logging': False,   # Verbose logging
    'save_frames': False,       # Save camera frames to disk
    'frame_save_path': './frames/',
}

# =============================================================================
# Helper Functions
# =============================================================================

def get_config(config_name):
    """
    Get configuration dictionary by name.
    
    Args:
        config_name (str): Name of configuration to retrieve
        
    Returns:
        dict: Configuration dictionary
        
    Raises:
        ValueError: If configuration name is not found
    """
    configs = {
        'camera': CAMERA_CONFIG,
        'control': CONTROL_CONFIG,
        'network': NETWORK_CONFIG,
        'logging': LOGGING_CONFIG,
        'display': DISPLAY_CONFIG,
        'telemetry': TELEMETRY_CONFIG,
        'motor': MOTOR_CONFIG,
        'safety': SAFETY_CONFIG,
        'dev': DEV_CONFIG,
    }
    
    if config_name not in configs:
        raise ValueError(f"Configuration '{config_name}' not found")
    
    return configs[config_name]


def validate_config():
    """
    Validate all configuration values.
    
    Returns:
        bool: True if all configurations are valid
        
    Raises:
        ValueError: If any configuration is invalid
    """
    # Validate camera config
    if CAMERA_CONFIG['width'] <= 0 or CAMERA_CONFIG['height'] <= 0:
        raise ValueError("Invalid camera resolution")
    
    if CAMERA_CONFIG['fps'] <= 0:
        raise ValueError("Invalid camera FPS")
    
    # Validate control config
    if CONTROL_CONFIG['setpoint'] <= 0:
        raise ValueError("Invalid setpoint distance")
    
    if CONTROL_CONFIG['kp_voltage'] < 0:
        raise ValueError("Invalid proportional gain")
    
    # Validate network config
    if not (1024 <= NETWORK_CONFIG['server_port'] <= 65535):
        raise ValueError("Invalid server port (must be 1024-65535)")
    
    return True


# Validate configuration on import
if __name__ != '__main__':
    try:
        validate_config()
    except ValueError as e:
        print(f"Configuration validation warning: {e}")

