"""
Core Module

Contains core functionality for the rover including camera interfaces
and hardware abstraction layers.

Classes:
    - RoverCamera: Intel RealSense camera interface
"""

from .RoverCamera import RoverCamera

__all__ = ['RoverCamera']

