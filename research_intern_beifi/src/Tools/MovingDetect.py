import cv2
import numpy as np

# Crear objeto capture de video
cap = cv2.VideoCapture(0)

# Crear objeto background subtractor
fgbg = cv2.createBackgroundSubtractorMOG2(detectShadows=False)

while True:
    # Leer cuadro actual del video
    ret, frame = cap.read()
    if not ret:
        break

    # Convertir a escala de grises y aplicar filtro gaussiano
    curr_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    curr_frame = cv2.GaussianBlur(curr_frame, (5, 5), 0)

    # Aplicar background subtraction
    fgmask = fgbg.apply(curr_frame)

    # Aplicar apertura y cierre para eliminar pequeñas regiones
    kernel = np.ones((5,5), np.uint8)
    opening = cv2.morphologyEx(fgmask, cv2.MORPH_OPEN, kernel)
    closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, kernel)

    # Encontrar contornos de las regiones de movimiento
    contours, hierarchy = cv2.findContours(closing, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Dibujar rectángulo alrededor de cada región de movimiento
    for cnt in contours:
        x, y, w, h = cv2.boundingRect(cnt)
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

    # Mostrar video en pantalla
    cv2.imshow("frame", frame)

    # Salir con tecla 'q'
    if cv2.waitKey(1) == ord('q'):
        break

# Liberar objeto capture y cerrar todas las ventanas
cap.release()
cv2.destroyAllWindows()