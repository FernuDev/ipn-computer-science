# Project Structure Overview

This document provides a visual overview of the complete project structure.

## 📁 Directory Tree

```
ipn-computer-science/
│
├── 📄 README.md                         # Main project documentation
├── 📄 LICENSE                           # MIT License
├── 📄 .gitignore                       # Git ignore rules
├── 📄 .editorconfig                    # Editor configuration
├── 📄 CONTRIBUTING.md                  # Contribution guidelines
├── 📄 CHANGELOG.md                     # Version history
├── 📄 AUTHORS                          # Contributors list
├── 📄 PROJECT_STRUCTURE.md            # This file
│
├── 📁 basic_programing_1am2/          # Basic Programming Course
│   ├── 📄 README.md                    # Course documentation
│   │
│   ├── 📁 C/                          # C Programming Exercises (83+ programs)
│   │   ├── 00_Bienvenida.c           # Hello World
│   │   ├── 01-09_*.c                 # Basic I/O and operations
│   │   ├── 10-21_*.c                 # Mathematical operations
│   │   ├── 22-31_*.c                 # Control structures
│   │   ├── 32-43_*.c                 # Loops (for, while, do-while)
│   │   ├── 44-53_*.c                 # Practical applications
│   │   ├── 54-67_*.c                 # Arrays and vectors
│   │   ├── 68-83_*.c                 # Matrices and linear algebra
│   │   ├── matrices.c                # Matrix operations
│   │   ├── matrices_vectors.cpp      # Vector/matrix C++ version
│   │   └── vector_d_size.c           # Dynamic vectors
│   │
│   └── 📁 Infografias_expo/          # Presentation materials
│       └── Infografia_NRLF_Parcial1.pdf
│
└── 📁 research_intern_beifi/          # Research Internship Project
    ├── 📄 README.md                    # Rover project documentation
    ├── 📄 requirements.txt             # Python dependencies
    ├── 📄 setup.py                     # Package installation script
    ├── 📄 Makefile                     # Development automation
    ├── 📄 config.py                    # Central configuration
    ├── 📄 main.py                      # Main control system
    │
    ├── 📁 src/                        # Source code
    │   ├── 📄 __init__.py             # Package initialization
    │   │
    │   ├── 📁 Core/                   # Core functionality
    │   │   ├── 📄 __init__.py
    │   │   └── 📄 RoverCamera.py      # RealSense camera interface
    │   │
    │   ├── 📁 Client/                 # Remote control client
    │   │   ├── 📄 __init__.py
    │   │   └── 📄 Client.py           # TCP client
    │   │
    │   ├── 📁 Server/                 # Communication server
    │   │   ├── 📄 __init__.py
    │   │   └── 📄 Server.py           # TCP server
    │   │
    │   ├── 📁 Tools/                  # Utility tools
    │   │   ├── 📄 Open_Camera.py      # Camera viewer
    │   │   ├── 📄 realsense_camera.py # Camera utilities
    │   │   ├── 📄 realsense_depth.py  # Depth processing
    │   │   ├── 📄 measure_object_distance.py
    │   │   ├── 📄 MovingDetect.py     # Motion detection
    │   │   ├── 📄 mask_rcnn.py        # Instance segmentation
    │   │   ├── 📄 detect distance.py
    │   │   ├── 📄 First_IA_Network.ipynb
    │   │   └── 📄 Object_Detection_Tf.ipynb
    │   │
    │   ├── 📁 Test/                   # Testing scripts
    │   │   ├── 📄 Jetson_Rover_Test.py
    │   │   ├── 📄 Jetson_Rover.py
    │   │   └── 📄 realsense_Rover.py
    │   │
    │   ├── 📁 Simulations/            # Mathematical simulations
    │   │   ├── 📄 Simulacion_1_ECD_PDI_Luis_Fernando.ipynb
    │   │   └── 📄 Simulacion_2_ECD_PDI_Luis_Fernando.ipynb
    │   │
    │   ├── 📁 Documentation/          # Technical documentation
    │   │   ├── 📄 Rover.ipynb         # Interactive docs
    │   │   ├── 📄 Rover.html          # HTML docs
    │   │   └── 📄 Rover.pdf           # PDF manual
    │   │
    │   └── 📁 img/                    # Images and diagrams
    │       ├── jetson-nano.jpg
    │       ├── Jetson.jpg
    │       └── Test_1.png
    │
    └── 📁 Arduino_File/               # Arduino code
        └── Arduino_File.ino            # Motor control
```

## 📊 Project Statistics

### Overall Project
- **Total Lines of Code**: ~15,000+
- **Programming Languages**: C, Python, C++, Arduino
- **Number of Files**: 150+
- **Documentation Files**: 10+

### Basic Programming (C)
- **Total Programs**: 83+
- **Topics Covered**: 30+
- **Lines of Code**: ~8,000+
- **Concepts**: Variables, Control Flow, Loops, Arrays, Matrices

### Research Project (Python)
- **Core Modules**: 4 (Core, Client, Server, Tools)
- **Test Scripts**: 10+
- **Simulations**: 2 Jupyter notebooks
- **Lines of Code**: ~5,000+
- **Dependencies**: 20+ Python packages

## 🏗️ Architecture Overview

```
┌─────────────────────────────────────────────────────────────┐
│                    IPN Computer Science                     │
│                    Academic Portfolio                       │
└──────────────────┬──────────────────────────────────────────┘
                   │
        ┌──────────┴──────────┐
        │                     │
┌───────▼────────┐   ┌────────▼─────────────┐
│ Basic          │   │ Research Internship  │
│ Programming    │   │ (Autonomous Rover)   │
│ (C Language)   │   │ (Python + Hardware)  │
└────────────────┘   └──────────────────────┘
        │                     │
        │                     │
   83+ Programs         ┌─────┴──────┐
   Organized by         │            │
   Complexity      Software      Hardware
                        │            │
                  ┌─────┴─────┐      │
                  │           │      │
            Vision    Control  │     │
            System    System   │     │
                 │       │     │     │
            RealSense  PID  Client- Intel
            Camera    Ctrl  Server  RealSense
                           │     │  Camera
                      Telemetry  │     +
                         &      Network Jetson
                     Analytics   Comm  Nano
```

## 🎯 Component Responsibilities

### Core Components

| Component | Responsibility | Key Files |
|-----------|---------------|-----------|
| **RoverCamera** | Camera interface and frame acquisition | `RoverCamera.py` |
| **JetsonRover** | Main control loop and navigation | `main.py` |
| **RoverClient** | Remote control interface | `Client.py` |
| **RoverServer** | Command reception and processing | `Server.py` |
| **Configuration** | Centralized settings | `config.py` |

### Support Components

| Component | Responsibility | Location |
|-----------|---------------|----------|
| **Tools** | Utilities and standalone scripts | `src/Tools/` |
| **Tests** | Testing and validation | `src/Test/` |
| **Simulations** | Mathematical modeling | `src/Simulations/` |
| **Documentation** | Technical docs and guides | `src/Documentation/` |

## 📚 Documentation Files

| File | Purpose | Audience |
|------|---------|----------|
| `README.md` (root) | Main project overview | Everyone |
| `README.md` (rover) | Rover technical docs | Developers |
| `README.md` (C) | C programming guide | Students |
| `CONTRIBUTING.md` | Contribution guidelines | Contributors |
| `CHANGELOG.md` | Version history | Maintainers |
| `AUTHORS` | Credits and contributors | Everyone |
| `LICENSE` | Legal terms (MIT) | Everyone |

## 🔧 Development Tools

### Build and Automation
- **Makefile** - Common development tasks
- **setup.py** - Python package installation
- **.editorconfig** - Code style configuration

### Quality Assurance
- **Linting**: flake8, pylint
- **Formatting**: black
- **Type Checking**: mypy
- **Testing**: pytest

### Documentation
- **Markdown** - README files
- **Jupyter** - Interactive notebooks
- **Docstrings** - API documentation

## 📦 Dependencies

### Python Packages (Core)
- `opencv-python` - Computer vision
- `pyrealsense2` - Camera SDK
- `numpy` - Numerical computing
- `matplotlib` - Visualization

### Python Packages (Optional)
- `tensorflow` - Deep learning
- `torch` - PyTorch
- `jupyter` - Notebooks

### System Requirements
- **For C Programs**: GCC compiler
- **For Rover**: CUDA, RealSense SDK, Python 3.8+

## 🚀 Quick Start Commands

### General
```bash
# View project structure
tree -L 2

# Count lines of code
cloc .
```

### C Programming
```bash
cd basic_programing_1am2/C
gcc -o program 01_Saludo.c
./program
```

### Rover Project
```bash
cd research_intern_beifi
make install       # Install dependencies
make run          # Run rover
make help         # Show all commands
```

## 📈 Future Structure Plans

Planned additions:
- `/tests` - Comprehensive test suite
- `/docs` - Sphinx-generated documentation
- `/scripts` - Utility scripts
- `/models` - Trained ML models
- `/data` - Sample datasets

---

## 📝 Notes

- All Python code follows PEP 8 standards
- C code uses 4-space indentation
- Documentation uses Markdown format
- Version control uses Git
- License: MIT (permissive open source)

---

<div align="center">

**Instituto Politécnico Nacional**

*La Técnica al Servicio de la Patria*

Last Updated: January 9, 2025

</div>

