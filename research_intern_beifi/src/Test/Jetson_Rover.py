import cv2
from realsense_Rover import *
import time

point = (320, 240)

class Jetson_Rover:

    camera_Rover = RoverCamera()
    distances = []
    time_elapsed = 0
    velocidad = 0

    def __init__(self):
        pass
    
    def calc_Velocity(self, distances, time_elapsed):
        # print(f'Velocidad : {((distances[0]-distances[-1]/len(distances))/1000)/(time_elapsed*1000):.2f} m/s')
        Distances = np.array(distances)
        sumDistances = Distances.sum()
        mayorDistance = Distances.max()
        self.velocidad = ((Distances[-1] - Distances[0])) /(time_elapsed)

        print(f'Distances: {Distances.shape}, en -1 : {Distances[-1]}, en 0: {Distances[0]}')

        if Distances[0] == 0 or Distances[1] == 0:
            self.velocidad = ((Distances[-1] - Distances[0])) / (time_elapsed)


    def draw_Point(self, bgr_frame, depth_colorMap, distance):
        cv2.circle(bgr_frame,(point[0], point[1]),2, (0,255,0), 2 )
        cv2.putText(bgr_frame,"{:.3f}m".format(distance),(point[0], point[1] -10 ), 1, 2, (0,255,0),2)

        cv2.circle(depth_colorMap,(point[0], point[1]),2, (0,255,0), 2 )
        cv2.putText(depth_colorMap,"{:.3}m".format(distance),(point[0]-12, point[1] -10 ), 1, 2, (0,255,0),2)

        #cv2.putText(bgr_frame,"{:.3f} mm/ms".format(self.velocidad), (point[0]-12, point[1]-40), 1,2,(0,255,0, 2) )


    def init_Rover(self):
        print("Iniciando Rover...")
        init = time.time()

        while True:

            state, depth_frame, bgr_frame, depth_colorMap= self.camera_Rover.get_frame()

            if not state:
                print("An error have ocurred, verify the camera conection and the enviroment")
                break
            
            distance = depth_frame.get_distance(point[0], point[1])

            self.distances.append(distance)

            end = time.time()

            self.time_elapsed += (end-init)

            if self.time_elapsed >0.9 and self.time_elapsed<1.5:

                if len(self.distances)>4:
                    self.calc_Velocity(self.distances, self.time_elapsed)
                # print(f'La diferencia de tiempos es: {self.time_elapsed:.3f} s')
                self.time_elapsed = 0
                self.distances = []
                

            self.draw_Point(bgr_frame, depth_colorMap, distance)
            
            cv2.imshow("Color_frame", bgr_frame)
            # cv2.imshow("Depth_frame", depth_frame)
            cv2.imshow("ColorMap", depth_colorMap)

            # print(f'Distancia al punto: {distance}mm')
            # print(f' Estado: {state}, Dimensiones de color: {bgr_frame.shape}, Dimensiones de profundidad: {depth_frame.shape} \n')
            # print(f' Dimensiones de color map: {depth_colormap.shape}')

            key = cv2.waitKey(1)

            if key == 27:
                break


rover = Jetson_Rover()

rover.init_Rover()