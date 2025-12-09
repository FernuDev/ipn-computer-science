# ============================================================================
# Makefile for Autonomous Rover Project
# ============================================================================
# Author: Luis Fernando
# Institution: Instituto Politécnico Nacional (IPN)
# Project: BEIFI Research Internship - Autonomous Rover
# ============================================================================

.PHONY: help install install-dev test clean lint format run server client docs

# Python interpreter
PYTHON := python3
PIP := pip3

# Directories
SRC_DIR := src
TEST_DIR := tests
DOCS_DIR := docs

# Colors for terminal output
COLOR_RESET := \033[0m
COLOR_BOLD := \033[1m
COLOR_GREEN := \033[32m
COLOR_YELLOW := \033[33m
COLOR_BLUE := \033[34m

# ============================================================================
# Help
# ============================================================================

help: ## Show this help message
	@echo "$(COLOR_BOLD)Autonomous Rover - Makefile Commands$(COLOR_RESET)"
	@echo ""
	@echo "$(COLOR_GREEN)Available commands:$(COLOR_RESET)"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "  $(COLOR_BLUE)%-15s$(COLOR_RESET) %s\n", $$1, $$2}'
	@echo ""

# ============================================================================
# Installation
# ============================================================================

install: ## Install production dependencies
	@echo "$(COLOR_GREEN)Installing production dependencies...$(COLOR_RESET)"
	$(PIP) install -r requirements.txt
	@echo "$(COLOR_GREEN)✓ Installation complete!$(COLOR_RESET)"

install-dev: ## Install development dependencies
	@echo "$(COLOR_GREEN)Installing development dependencies...$(COLOR_RESET)"
	$(PIP) install -r requirements.txt
	$(PIP) install pytest pytest-cov flake8 black pylint mypy
	@echo "$(COLOR_GREEN)✓ Development setup complete!$(COLOR_RESET)"

upgrade: ## Upgrade all dependencies
	@echo "$(COLOR_GREEN)Upgrading dependencies...$(COLOR_RESET)"
	$(PIP) install --upgrade -r requirements.txt
	@echo "$(COLOR_GREEN)✓ Upgrade complete!$(COLOR_RESET)"

# ============================================================================
# Running
# ============================================================================

run: ## Run the main rover control system
	@echo "$(COLOR_GREEN)Starting Autonomous Rover...$(COLOR_RESET)"
	$(PYTHON) main.py

server: ## Start the rover server
	@echo "$(COLOR_GREEN)Starting Rover Server...$(COLOR_RESET)"
	$(PYTHON) -m src.Server.Server

client: ## Start the rover client
	@echo "$(COLOR_GREEN)Starting Rover Client...$(COLOR_RESET)"
	$(PYTHON) -m src.Client.Client

camera: ## Open camera viewer
	@echo "$(COLOR_GREEN)Opening camera viewer...$(COLOR_RESET)"
	$(PYTHON) src/Tools/Open_Camera.py

# ============================================================================
# Testing
# ============================================================================

test: ## Run all tests
	@echo "$(COLOR_GREEN)Running tests...$(COLOR_RESET)"
	$(PYTHON) -m pytest tests/ -v

test-cov: ## Run tests with coverage report
	@echo "$(COLOR_GREEN)Running tests with coverage...$(COLOR_RESET)"
	$(PYTHON) -m pytest tests/ -v --cov=$(SRC_DIR) --cov-report=html
	@echo "$(COLOR_GREEN)✓ Coverage report generated in htmlcov/$(COLOR_RESET)"

test-camera: ## Test camera connection
	@echo "$(COLOR_GREEN)Testing camera connection...$(COLOR_RESET)"
	$(PYTHON) src/Test/realsense_Rover.py

# ============================================================================
# Code Quality
# ============================================================================

lint: ## Run code linters
	@echo "$(COLOR_GREEN)Running flake8...$(COLOR_RESET)"
	$(PYTHON) -m flake8 $(SRC_DIR) main.py --max-line-length=88 --extend-ignore=E203,W503
	@echo "$(COLOR_GREEN)Running pylint...$(COLOR_RESET)"
	$(PYTHON) -m pylint $(SRC_DIR) main.py --disable=C0111,R0903
	@echo "$(COLOR_GREEN)✓ Linting complete!$(COLOR_RESET)"

format: ## Format code with black
	@echo "$(COLOR_GREEN)Formatting code with black...$(COLOR_RESET)"
	$(PYTHON) -m black $(SRC_DIR) main.py
	@echo "$(COLOR_GREEN)✓ Formatting complete!$(COLOR_RESET)"

format-check: ## Check code formatting
	@echo "$(COLOR_GREEN)Checking code formatting...$(COLOR_RESET)"
	$(PYTHON) -m black --check $(SRC_DIR) main.py

type-check: ## Run type checking with mypy
	@echo "$(COLOR_GREEN)Running type checker...$(COLOR_RESET)"
	$(PYTHON) -m mypy $(SRC_DIR) main.py --ignore-missing-imports

# ============================================================================
# Documentation
# ============================================================================

docs: ## Generate documentation
	@echo "$(COLOR_GREEN)Generating documentation...$(COLOR_RESET)"
	jupyter nbconvert src/Documentation/Rover.ipynb --to html
	@echo "$(COLOR_GREEN)✓ Documentation generated!$(COLOR_RESET)"

notebook: ## Start Jupyter notebook
	@echo "$(COLOR_GREEN)Starting Jupyter notebook...$(COLOR_RESET)"
	jupyter notebook

simulation: ## Run PID simulation
	@echo "$(COLOR_GREEN)Opening PID simulation...$(COLOR_RESET)"
	jupyter notebook src/Simulations/Simulacion_1_ECD_PDI_Luis_Fernando.ipynb

# ============================================================================
# Cleaning
# ============================================================================

clean: ## Clean build artifacts and cache
	@echo "$(COLOR_GREEN)Cleaning build artifacts...$(COLOR_RESET)"
	find . -type f -name '*.pyc' -delete
	find . -type d -name '__pycache__' -delete
	find . -type d -name '*.egg-info' -exec rm -rf {} + 2>/dev/null || true
	rm -rf build/ dist/ .pytest_cache/ .coverage htmlcov/ .mypy_cache/
	@echo "$(COLOR_GREEN)✓ Cleanup complete!$(COLOR_RESET)"

clean-frames: ## Clean saved camera frames
	@echo "$(COLOR_YELLOW)Cleaning saved frames...$(COLOR_RESET)"
	rm -rf frames/*.png frames/*.jpg
	@echo "$(COLOR_GREEN)✓ Frames cleaned!$(COLOR_RESET)"

# ============================================================================
# Development
# ============================================================================

dev: install-dev ## Setup development environment
	@echo "$(COLOR_GREEN)Development environment ready!$(COLOR_RESET)"

check: lint type-check test ## Run all checks
	@echo "$(COLOR_GREEN)✓ All checks passed!$(COLOR_RESET)"

# ============================================================================
# Project Info
# ============================================================================

info: ## Show project information
	@echo "$(COLOR_BOLD)Autonomous Rover Project$(COLOR_RESET)"
	@echo "========================="
	@echo "Institution: $(COLOR_GREEN)Instituto Politécnico Nacional (IPN)$(COLOR_RESET)"
	@echo "Program: $(COLOR_GREEN)BEIFI Research Internship$(COLOR_RESET)"
	@echo "Python: $(COLOR_BLUE)$$($(PYTHON) --version)$(COLOR_RESET)"
	@echo "Pip: $(COLOR_BLUE)$$($(PIP) --version)$(COLOR_RESET)"
	@echo ""
	@echo "$(COLOR_BOLD)Dependencies:$(COLOR_RESET)"
	@$(PIP) list | grep -E "(opencv|pyrealsense|numpy|matplotlib)"
	@echo ""

# ============================================================================
# Quick Start
# ============================================================================

quickstart: install ## Quick start guide
	@echo "$(COLOR_BOLD)Quick Start Guide$(COLOR_RESET)"
	@echo "=================="
	@echo ""
	@echo "1. Test camera connection:"
	@echo "   $(COLOR_BLUE)make test-camera$(COLOR_RESET)"
	@echo ""
	@echo "2. Run the rover system:"
	@echo "   $(COLOR_BLUE)make run$(COLOR_RESET)"
	@echo ""
	@echo "3. View simulations:"
	@echo "   $(COLOR_BLUE)make simulation$(COLOR_RESET)"
	@echo ""
	@echo "For more commands, run: $(COLOR_BLUE)make help$(COLOR_RESET)"
	@echo ""

# ============================================================================
# Default target
# ============================================================================

.DEFAULT_GOAL := help

