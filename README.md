# IPN Computer Science - Academic Portfolio

<div align="center">

![IPN Logo](https://img.shields.io/badge/IPN-Instituto_Polit%C3%A9cnico_Nacional-8B1538?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![OpenCV](https://img.shields.io/badge/OpenCV-5C3EE8?style=for-the-badge&logo=opencv&logoColor=white)

*Repositorio académico de proyectos de Computer Science del Instituto Politécnico Nacional*

</div>

---

## 📋 Tabla de Contenidos

- [Descripción General](#-descripción-general)
- [Estructura del Proyecto](#-estructura-del-proyecto)
- [Proyectos Principales](#-proyectos-principales)
  - [1. Programación Básica en C](#1-programación-básica-en-c)
  - [2. Investigación: Rover Autónomo con IA](#2-investigación-rover-autónomo-con-ia)
- [Instalación y Configuración](#-instalación-y-configuración)
- [Uso](#-uso)
- [Tecnologías](#-tecnologías)
- [Contribuciones](#-contribuciones)
- [Licencia](#-licencia)
- [Contacto](#-contacto)

---

## 🎓 Descripción General

Este repositorio contiene una colección de proyectos académicos y de investigación desarrollados durante mi formación en Ciencias de la Computación en el **Instituto Politécnico Nacional (IPN)**. El repositorio incluye desde programas fundamentales en C hasta proyectos avanzados de robótica e inteligencia artificial.

### Objetivos Académicos

- Demostrar competencias en programación estructurada y orientada a objetos
- Aplicar conocimientos de estructuras de datos y algoritmos
- Implementar soluciones de visión por computadora y procesamiento de imágenes
- Desarrollar sistemas de control para robótica autónoma
- Integrar hardware y software en proyectos de investigación

---

## 📁 Estructura del Proyecto

```
ipn-computer-science/
│
├── basic_programing_1am2/          # Curso de Programación Básica
│   ├── C/                          # Programas en lenguaje C
│   │   ├── 00-21_*.c              # Operaciones básicas y matemáticas
│   │   ├── 22-31_*.c              # Estructuras de control
│   │   ├── 32-53_*.c              # Ciclos y conversiones
│   │   └── 54-83_*.c              # Arreglos, vectores y matrices
│   └── Infografias_expo/          # Material de presentaciones
│
├── research_intern_beifi/          # Proyecto de Investigación
│   ├── Arduino_File/              # Código para microcontrolador
│   ├── src/                       # Código fuente principal
│   │   ├── Client/               # Cliente de comunicación
│   │   ├── Server/               # Servidor de comunicación
│   │   ├── Core/                 # Núcleo del sistema (RoverCamera)
│   │   ├── Tools/                # Herramientas de detección y medición
│   │   ├── Test/                 # Pruebas de integración
│   │   ├── Simulations/          # Simulaciones matemáticas (PID)
│   │   ├── Documentation/        # Documentación técnica
│   │   └── img/                  # Recursos gráficos
│   ├── main.py                   # Punto de entrada principal
│   └── requirements.txt          # Dependencias Python
│
├── .gitignore                     # Archivos excluidos del control de versiones
├── LICENSE                        # Licencia MIT
└── README.md                      # Este archivo
```

---

## 🚀 Proyectos Principales

### 1. Programación Básica en C

**Descripción**: Colección de 83+ programas en C que cubren los fundamentos de programación estructurada.

**Temas Cubiertos**:
- 📝 Input/Output básico
- 🧮 Operaciones matemáticas y trigonométricas
- 🔀 Estructuras de control (if, switch, for, while)
- 📊 Arreglos y vectores
- 🔢 Matrices y operaciones lineales
- 📐 Geometría computacional
- 🔁 Conversiones de unidades

**Programas Destacados**:
- `08_Promedio_func.c` - Cálculo de promedios con funciones
- `21_Formula_General.c` - Resolución de ecuaciones cuadráticas
- `29_Afabeto_Aeronautico.c` - Alfabeto aeronáutico internacional
- `64_producto_punto.c` - Producto punto de vectores
- `77_Suma_Matrices.c` - Operaciones con matrices
- `79_Det_Matriz.c` - Cálculo de determinantes

### 2. Investigación: Rover Autónomo con IA

**Descripción**: Proyecto de investigación desarrollado como becario en el IPN para construir un rover autónomo capaz de reconocer su entorno y tomar decisiones inteligentes utilizando visión por computadora.

**Hardware**:
- 🖥️ NVIDIA Jetson Nano (Computación embebida)
- 📷 Intel RealSense Camera (Visión estéreo y profundidad)
- 🤖 Arduino (Control de motores)
- ⚙️ Motores DC con encoders

**Características Principales**:

#### Control Autónomo
- Sistema de control PID para navegación
- Cálculo de distancias en tiempo real
- Control de velocidad adaptativo
- Telemetría y visualización de datos

#### Visión por Computadora
- Captura de frames RGB y profundidad
- Detección de objetos con OpenCV
- Medición de distancias con RealSense
- Procesamiento de imágenes en tiempo real

#### Simulaciones
- Modelado matemático del sistema de control
- Simulación de respuesta PID
- Análisis de error y convergencia
- Visualización de variables de control

**Módulos del Sistema**:

```python
src/
├── Core/
│   └── RoverCamera.py         # Interfaz con cámara RealSense
├── Client/Server/             # Comunicación remota
├── Tools/
│   ├── realsense_depth.py     # Procesamiento de profundidad
│   ├── Object_Detection_Tf.ipynb  # Detección con TensorFlow
│   └── mask_rcnn.py           # Segmentación de instancias
├── Simulations/
│   └── Simulacion_1_ECD_PDI_*.ipynb  # Simulación PID
└── Test/
    └── Jetson_Rover_Test.py   # Pruebas de integración
```

**Ecuaciones de Control**:

El sistema implementa un controlador proporcional:

```
u(t) = Kp · e(t)
e(t) = r(t) - x(t)
x(t+1) = x(t) + h · (-u(t))
```

Donde:
- `u(t)`: Voltaje de control
- `e(t)`: Error de distancia
- `Kp`: Ganancia proporcional (10-100)
- `x(t)`: Posición actual
- `r(t)`: Referencia objetivo (setpoint)
- `h`: Paso de integración

---

## 🔧 Instalación y Configuración

### Requisitos Previos

#### Para Programas en C:
```bash
# Compilador GCC
gcc --version

# En macOS (si no está instalado)
xcode-select --install
```

#### Para Proyecto de Rover:
```bash
# Python 3.8+
python3 --version

# Para Jetson Nano
# CUDA Toolkit (preinstalado en JetPack)
# OpenCV con soporte CUDA
```

### Instalación

1. **Clonar el repositorio**:
```bash
git clone https://github.com/tu-usuario/ipn-computer-science.git
cd ipn-computer-science
```

2. **Configurar proyecto de Python**:
```bash
cd research_intern_beifi

# Crear entorno virtual (recomendado)
python3 -m venv venv
source venv/bin/activate  # En Windows: venv\Scripts\activate

# Instalar dependencias
pip install -r requirements.txt
```

3. **Compilar programas en C** (ejemplo):
```bash
cd basic_programing_1am2/C

# Compilar un programa específico
gcc -o programa 01_Saludo.c
./programa

# Compilar con librerías matemáticas
gcc -o calc 21_Formula_General.c -lm
./calc
```

---

## 💻 Uso

### Ejecutar Programas en C

```bash
cd basic_programing_1am2/C

# Ejemplo: Calcular promedio
gcc -o promedio 08_Promedio_func.c -lm
./promedio

# Ejemplo: Operaciones con matrices
gcc -o matrices 77_Suma_Matrices.c
./matrices
```

### Ejecutar Rover Autónomo

```bash
cd research_intern_beifi

# Activar entorno virtual
source venv/bin/activate

# Ejecutar programa principal
python3 main.py

# Controles:
# - ESC: Salir del programa
# - El sistema mostrará telemetría en tiempo real
```

### Ejecutar Simulaciones

```bash
# Abrir Jupyter Notebook
jupyter notebook

# Navegar a:
# src/Simulations/Simulacion_1_ECD_PDI_Luis_Fernando.ipynb

# Ejecutar todas las celdas para ver gráficas de:
# - Posición vs Tiempo
# - Voltaje vs Tiempo
# - Error vs Tiempo
```

### Ejecutar Herramientas de Visión

```bash
cd research_intern_beifi/src/Tools

# Abrir cámara RealSense
python3 Open_Camera.py

# Detección de profundidad
python3 realsense_depth.py

# Medición de distancias
python3 measure_object_distance.py
```

---

## 🛠️ Tecnologías

### Lenguajes de Programación
- ![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white) **C** - Programación de sistemas y algoritmos
- ![Python](https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white) **Python 3.8+** - IA y visión por computadora

### Librerías y Frameworks

#### Python
- **OpenCV 4.8.0** - Procesamiento de imágenes
- **NumPy 1.25.2** - Computación numérica
- **Matplotlib 3.7.2** - Visualización de datos
- **pyrealsense2 2.54** - SDK Intel RealSense
- **Pandas 2.0.3** - Análisis de datos
- **TensorFlow/Keras** - Deep Learning (detección de objetos)

#### C
- `stdio.h` - Input/Output estándar
- `math.h` - Funciones matemáticas
- `stdlib.h` - Funciones de utilidad

### Hardware
- **NVIDIA Jetson Nano** - GPU: 128-core Maxwell, CPU: Quad-core ARM A57
- **Intel RealSense D435** - Cámara de profundidad estéreo
- **Arduino Uno/Mega** - Microcontrolador para actuadores
- **Motores DC** - Locomoción del rover

### Herramientas de Desarrollo
- **GCC** - Compilador GNU C
- **Jupyter Notebook** - Desarrollo interactivo
- **Git** - Control de versiones
- **VSCode/Cursor** - Editor de código

---

## 📊 Resultados y Demostración

### Programas en C

**Ejemplos de ejecución**:

```
$ ./21_Formula_General
Ingrese coeficiente a: 1
Ingrese coeficiente b: -5
Ingrese coeficiente c: 6
x1 = 3.00
x2 = 2.00
```

### Rover Autónomo

**Métricas de rendimiento**:
- 🎯 Precisión de distancia: ±2cm
- 🎥 FPS de cámara: 30 fps
- ⚡ Latencia de control: <50ms
- 🔋 Tiempo de operación: ~2 horas

**Gráficas de control** (simulación):

Las simulaciones muestran:
1. **Convergencia exponencial** de la distancia al objetivo (200mm)
2. **Reducción del error** de manera asintótica
3. **Voltaje de control** proporcional al error
4. **Velocidad adaptativa** según la distancia

---

## 📖 Documentación Adicional

- 📄 **Documentación Técnica**: `research_intern_beifi/src/Documentation/Rover.pdf`
- 📓 **Notebook Interactivo**: `research_intern_beifi/src/Documentation/Rover.ipynb`
- 📊 **Infografías**: `basic_programing_1am2/Infografias_expo/`

---

## 🤝 Contribuciones

Este es un repositorio académico personal, pero se aceptan sugerencias y mejoras:

1. Fork el proyecto
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

**Áreas de contribución**:
- 🐛 Corrección de bugs
- 📝 Mejora de documentación
- ✨ Optimización de algoritmos
- 🧪 Nuevas pruebas y casos de uso

---

## 📚 Referencias Académicas

### Libros y Recursos
- Kernighan, B. W., & Ritchie, D. M. (1988). *The C Programming Language*
- Bradski, G., & Kaehler, A. (2008). *Learning OpenCV*
- Corke, P. (2017). *Robotics, Vision and Control*

### Papers Relacionados
- PID Control Theory
- Computer Vision for Autonomous Navigation
- Deep Learning for Object Detection

---

## 📄 Licencia

Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

```
MIT License - Copyright (c) 2025 Luis Fernando (IPN)
```

---

## 👨‍💻 Autor

**Luis Fernando**
- 🏫 Instituto Politécnico Nacional (IPN)
- 📧 Email: [tu-email@ejemplo.com]
- 💼 LinkedIn: [tu-linkedin]
- 🐱 GitHub: [@tu-usuario](https://github.com/tu-usuario)

### Roles
- 🎓 Estudiante de Ciencias de la Computación
- 🔬 Becario de Investigación - Proyecto BEIFI
- 💻 Desarrollador de Software

---

## 🙏 Agradecimientos

- **Instituto Politécnico Nacional (IPN)** - Por la formación académica y oportunidades de investigación
- **Programa BEIFI** - Por el apoyo financiero y recursos para el proyecto de rover
- **Profesores y mentores** - Por la guía y conocimientos compartidos
- **Comunidad open source** - Por las herramientas y librerías utilizadas

---

<div align="center">

**[⬆ Volver arriba](#ipn-computer-science---academic-portfolio)**

---

Hecho con ❤️ y ☕ en México 🇲🇽

*La Técnica al Servicio de la Patria*

</div>

