import cv2 
import numpy as np

# configurando la camara, tomando el primer frame y 
# Convirtiendolo a gray
video = cv2.VideoCapture(0)
ret, frame = video.read()

while True:
    #Leyendo cada frame nuevamente
    ret, frame = video.read()
    cv2.imshow("frame", frame)
    # cv2.imshow("frame", frame_diff)

    if cv2.waitKey(1) == 27:
        break

video.release()






