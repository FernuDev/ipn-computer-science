# Contributing Guide

Thank you for considering contributing to this academic project! This document provides guidelines for contributing to the IPN Computer Science repository.

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Style Guidelines](#style-guidelines)
- [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)

---

## 📜 Code of Conduct

This is an academic project from Instituto Politécnico Nacional (IPN). By participating, you are expected to:

- Be respectful and professional
- Provide constructive feedback
- Focus on learning and improvement
- Credit original authors

---

## 🚀 Getting Started

### Prerequisites

- Git installed on your system
- GCC compiler for C programs
- Python 3.8+ for the rover project
- Familiarity with the project structure

### Setting Up Development Environment

1. **Fork the repository**:
```bash
# Click the "Fork" button on GitHub
```

2. **Clone your fork**:
```bash
git clone https://github.com/YOUR-USERNAME/ipn-computer-science.git
cd ipn-computer-science
```

3. **Add upstream remote**:
```bash
git remote add upstream https://github.com/ORIGINAL-OWNER/ipn-computer-science.git
```

4. **Create a branch**:
```bash
git checkout -b feature/your-feature-name
```

---

## 🤝 How to Contribute

### Reporting Bugs

If you find a bug, please create an issue with:

- **Title**: Brief description of the bug
- **Description**: Detailed explanation
- **Steps to reproduce**
- **Expected behavior**
- **Actual behavior**
- **Environment**: OS, compiler version, etc.

### Suggesting Enhancements

Enhancement suggestions are welcome! Include:

- **Clear title**
- **Detailed description** of the enhancement
- **Use case**: Why is this useful?
- **Proposed implementation** (if applicable)

### Adding New Programs (C)

When adding new C programs to `basic_programing_1am2/`:

1. Follow the naming convention: `##_Descriptive_Name.c`
2. Include header comments:
```c
/*
 * Program: Descriptive Name
 * Description: What the program does
 * Author: Your Name
 * Date: YYYY-MM-DD
 */
```
3. Add appropriate comments
4. Test thoroughly before submitting

### Improving Documentation

- Fix typos and grammatical errors
- Improve clarity and organization
- Add examples and diagrams
- Translate content (if applicable)

---

## 📏 Style Guidelines

### C Programming

Follow these conventions for C code:

```c
// Include guards for headers
#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// Includes
#include <stdio.h>
#include <math.h>

// Constants in UPPERCASE
#define MAX_SIZE 100
#define PI 3.14159265

// Function names in snake_case
int calculate_sum(int a, int b) {
    // Variables in snake_case
    int result;
    
    // Clear logic with comments
    result = a + b;
    
    return result;
}

// Main function
int main() {
    // Indentation: 4 spaces
    printf("Hello, World!\n");
    
    return 0;
}

#endif // HEADER_NAME_H
```

### Python Programming

Follow PEP 8 style guide:

```python
"""
Module docstring explaining purpose.

Author: Your Name
Date: YYYY-MM-DD
"""

import os
import sys
from typing import List, Optional

# Constants in UPPERCASE
MAX_CONNECTIONS = 10
DEFAULT_PORT = 8485

class MyClass:
    """Class docstring."""
    
    def __init__(self, param: str):
        """Initialize with parameter."""
        self.param = param
    
    def my_method(self, value: int) -> bool:
        """
        Method docstring.
        
        Args:
            value: Description of parameter
            
        Returns:
            bool: Description of return value
        """
        return True

def my_function(x: int, y: int) -> int:
    """
    Function docstring.
    
    Args:
        x: First parameter
        y: Second parameter
        
    Returns:
        int: The sum of x and y
    """
    return x + y
```

### Documentation (Markdown)

- Use clear headings
- Include code examples
- Add badges where appropriate
- Keep lines under 80 characters when possible
- Use tables for structured data

---

## 📝 Commit Guidelines

### Commit Message Format

```
<type>(<scope>): <subject>

<body>

<footer>
```

### Types

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Maintenance tasks

### Examples

```bash
feat(rover): add PID controller implementation

Implement full PID controller with tunable parameters.
Includes integral and derivative terms for better control.

Closes #123
```

```bash
fix(camera): resolve memory leak in frame acquisition

Fixed memory leak caused by not releasing RealSense frames.
Added proper cleanup in destructor.

Fixes #456
```

```bash
docs(readme): update installation instructions

Added more detailed steps for Jetson Nano setup.
Included troubleshooting section.
```

---

## 🔄 Pull Request Process

### Before Submitting

1. **Update your fork**:
```bash
git fetch upstream
git merge upstream/main
```

2. **Run tests** (if applicable):
```bash
# For C programs
gcc -Wall -Wextra your_program.c -lm
./a.out

# For Python
python -m pytest tests/
```

3. **Update documentation** if needed

4. **Check code style**:
```bash
# For Python
flake8 your_module.py
black --check your_module.py
```

### Submitting the Pull Request

1. **Push to your fork**:
```bash
git push origin feature/your-feature-name
```

2. **Create Pull Request** on GitHub

3. **Fill out the PR template**:
```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Code refactoring

## Testing
Describe how you tested your changes

## Checklist
- [ ] Code follows style guidelines
- [ ] Comments added where necessary
- [ ] Documentation updated
- [ ] Changes generate no new warnings
- [ ] Added tests (if applicable)
```

### Review Process

- Maintainers will review your PR
- Address feedback and comments
- Make requested changes
- Once approved, your PR will be merged

---

## 🧪 Testing

### C Programs

```bash
# Compile with warnings
gcc -Wall -Wextra -pedantic program.c -lm -o program

# Test with sample input
./program < test_input.txt

# Check for memory leaks (if available)
valgrind ./program
```

### Python Code

```bash
# Install development dependencies
pip install -r requirements-dev.txt

# Run tests
pytest tests/

# Check coverage
pytest --cov=src tests/

# Lint code
flake8 src/
pylint src/

# Format code
black src/
```

---

## 📚 Resources

### Learning Resources

- [Git Tutorial](https://git-scm.com/docs/gittutorial)
- [C Programming Guide](https://www.learn-c.org/)
- [Python PEP 8](https://pep8.org/)
- [Markdown Guide](https://www.markdownguide.org/)

### Project-Specific

- [Intel RealSense SDK](https://github.com/IntelRealSense/librealsense)
- [OpenCV Documentation](https://docs.opencv.org/)
- [NVIDIA Jetson](https://developer.nvidia.com/embedded/jetson-nano-developer-kit)

---

## ❓ Questions?

If you have questions:

1. Check existing issues and documentation
2. Create a new issue with the `question` label
3. Contact the maintainer

---

## 🙏 Thank You!

Your contributions help improve this academic project and benefit future students. Thank you for taking the time to contribute!

---

<div align="center">

**Instituto Politécnico Nacional**

*La Técnica al Servicio de la Patria*

</div>

