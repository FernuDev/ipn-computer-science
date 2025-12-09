# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned
- Full PID controller implementation (integral and derivative terms)
- Machine learning object detection integration
- Path planning algorithms
- Mobile app for remote control
- SLAM implementation

---

## [1.0.0] - 2025-01-09

### Added
- **Project Structure**
  - Global README.md with comprehensive documentation
  - MIT License
  - Global .gitignore with Python, C, and project-specific rules
  - CONTRIBUTING.md with contribution guidelines
  - CHANGELOG.md for version tracking
  - .editorconfig for consistent code style

- **Research Internship Project (research_intern_beifi/)**
  - Refactored `main.py` with improved structure and documentation
  - Enhanced `RoverCamera.py` with proper error handling and logging
  - Improved `Client.py` with class-based design and better error handling
  - Enhanced `Server.py` with robust connection handling
  - Created `config.py` for centralized configuration
  - Added `setup.py` for package installation
  - Created `Makefile` for common development tasks
  - Comprehensive README.md for the rover project
  - Enhanced `requirements.txt` with detailed comments and sections
  - Added `__init__.py` files for all modules
  
- **Basic Programming (basic_programing_1am2/)**
  - Comprehensive README.md documenting all 83+ C programs
  - Organized program index by difficulty level
  - Added compilation instructions and examples
  - Troubleshooting guide

### Changed
- **Code Quality**
  - Added type hints to Python code
  - Improved docstrings for all classes and methods
  - Implemented proper logging instead of print statements
  - Better error handling throughout the codebase
  
- **Documentation**
  - Professional formatting with badges and emoji
  - Clear structure with table of contents
  - Code examples and usage instructions
  - Detailed API documentation

### Improved
- **RoverCamera Module**
  - Added context manager support (`with` statement)
  - Improved frame acquisition error handling
  - Added logging for debugging
  - Configurable resolution and frame rate
  
- **JetsonRover Class**
  - Separated telemetry data into structured dictionary
  - Better method organization
  - Improved visualization with matplotlib
  - Added statistics reporting

- **Network Modules**
  - Class-based client and server implementations
  - Proper socket cleanup and resource management
  - Better command processing
  - Interactive and programmatic modes

---

## [0.2.0] - 2024-12-XX (Previous Version)

### Added
- Initial rover control system
- Basic PID simulation notebooks
- RealSense camera integration
- TCP client-server communication
- Object detection tools
- Basic documentation

### Known Issues
- Global variables in main.py
- Limited error handling
- Missing type hints
- Sparse documentation

---

## [0.1.0] - 2024-XX-XX (Initial Release)

### Added
- Basic C programming exercises (00-83)
- Initial rover prototype
- Camera testing scripts
- Arduino motor control code

---

## Version History Summary

| Version | Date | Highlights |
|---------|------|------------|
| 1.0.0 | 2025-01-09 | Professional refactoring, comprehensive docs |
| 0.2.0 | 2024-12-XX | Rover control system, simulations |
| 0.1.0 | 2024-XX-XX | Initial project setup |

---

## Migration Guide

### From 0.2.0 to 1.0.0

**Main Changes:**

1. **Import Changes**:
```python
# Old
from src.Core.RoverCamera import RoverCamera

# New (still works)
from src.Core.RoverCamera import RoverCamera
# Or
from src.Core import RoverCamera
```

2. **Configuration**:
```python
# Old (hardcoded values)
camera = RoverCamera()

# New (configurable)
from config import CAMERA_CONFIG
camera = RoverCamera(**CAMERA_CONFIG)
```

3. **Class Name Change**:
```python
# Old
rover = Jetson_Rover()

# New
rover = JetsonRover()
```

4. **Telemetry Access**:
```python
# Old
times = times  # Global variable

# New
times = rover.telemetry['times']
```

---

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for details on how to contribute to this project.

---

## License

This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

---

## Authors

- **Luis Fernando** - *Initial work and development* - Instituto Politécnico Nacional (IPN)

See [AUTHORS](AUTHORS) for a complete list of contributors.

---

## Acknowledgments

- Instituto Politécnico Nacional (IPN) - Academic institution and research support
- BEIFI Program - Research internship funding
- Intel - RealSense SDK and hardware
- NVIDIA - Jetson Nano platform

---

[Unreleased]: https://github.com/your-username/ipn-computer-science/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/your-username/ipn-computer-science/releases/tag/v1.0.0
[0.2.0]: https://github.com/your-username/ipn-computer-science/releases/tag/v0.2.0
[0.1.0]: https://github.com/your-username/ipn-computer-science/releases/tag/v0.1.0

