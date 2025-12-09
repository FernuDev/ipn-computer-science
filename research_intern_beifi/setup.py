"""
Setup script for Autonomous Rover package.

This script allows the rover software to be installed as a Python package.

Author: Luis Fernando
Institution: Instituto Politécnico Nacional (IPN)
Project: BEIFI Research Internship
"""

from setuptools import setup, find_packages
import os

# Read the README file
def read_readme():
    """Read README.md for long description."""
    readme_path = os.path.join(os.path.dirname(__file__), 'README.md')
    if os.path.exists(readme_path):
        with open(readme_path, 'r', encoding='utf-8') as f:
            return f.read()
    return ''

# Read requirements
def read_requirements():
    """Read requirements.txt."""
    req_path = os.path.join(os.path.dirname(__file__), 'requirements.txt')
    requirements = []
    if os.path.exists(req_path):
        with open(req_path, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                # Skip comments and empty lines
                if line and not line.startswith('#'):
                    requirements.append(line)
    return requirements

setup(
    # Package information
    name='autonomous-rover',
    version='1.0.0',
    author='Luis Fernando',
    author_email='your-email@example.com',
    description='Autonomous rover with computer vision and depth sensing',
    long_description=read_readme(),
    long_description_content_type='text/markdown',
    url='https://github.com/your-username/ipn-computer-science',
    
    # Package structure
    packages=find_packages(exclude=['tests', 'docs', 'Arduino_File']),
    package_dir={'': '.'},
    
    # Dependencies
    install_requires=read_requirements(),
    
    # Python version requirement
    python_requires='>=3.8',
    
    # Additional dependencies
    extras_require={
        'dev': [
            'pytest>=7.0.0',
            'pytest-cov>=3.0.0',
            'flake8>=4.0.0',
            'black>=22.0.0',
            'pylint>=2.12.0',
            'mypy>=0.950',
            'jupyter>=1.0.0',
        ],
        'ml': [
            'tensorflow>=2.10.0',
            'torch>=1.13.0',
            'torchvision>=0.14.0',
        ],
    },
    
    # Entry points (command-line scripts)
    entry_points={
        'console_scripts': [
            'rover-run=main:main',
            'rover-server=src.Server.Server:main',
            'rover-client=src.Client.Client:main',
        ],
    },
    
    # Classifiers
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Education',
        'Intended Audience :: Science/Research',
        'Topic :: Scientific/Engineering :: Artificial Intelligence',
        'Topic :: Scientific/Engineering :: Image Recognition',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Operating System :: POSIX :: Linux',
        'Operating System :: MacOS :: MacOS X',
    ],
    
    # Keywords
    keywords=[
        'robotics',
        'computer-vision',
        'autonomous-navigation',
        'realsense',
        'jetson-nano',
        'opencv',
        'depth-sensing',
        'pid-control',
    ],
    
    # Project URLs
    project_urls={
        'Bug Reports': 'https://github.com/your-username/ipn-computer-science/issues',
        'Source': 'https://github.com/your-username/ipn-computer-science',
        'Documentation': 'https://github.com/your-username/ipn-computer-science/wiki',
    },
    
    # Include additional files
    include_package_data=True,
    package_data={
        '': ['*.md', '*.txt', '*.ini'],
        'src': ['Documentation/*.html', 'img/*.jpg', 'img/*.png'],
    },
    
    # Zip safe
    zip_safe=False,
)

