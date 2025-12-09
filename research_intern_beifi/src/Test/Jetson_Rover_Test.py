import pyrealsense2 as rs
import cv2 
import numpy as np
from math import e

point = (320,240)
distances = []

class RoverCamera:
    def __init__(self) -> None:
        pass
    # Configure depth and color streams
        self.pipeline = rs.pipeline()
        config = rs.config()

        # Get device product line for setting a supporting resolution
        pipeline_wrapper = rs.pipeline_wrapper(self.pipeline)
        pipeline_profile = config.resolve(pipeline_wrapper)
        device = pipeline_profile.get_device()
        device_product_line = str(device.get_info(rs.camera_info.product_line))

        config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)



        # Start streaming
        self.pipeline.start(config)

    def get_frames(self):
        frames = self.pipeline.wait_for_frames()

        depth_frame = frames.get_depth_frame()
        color_frame = frames.get_color_frame()

        depth_time = depth_frame.get_timestamp()

        # # Apply filter to fill the Holes in the depth image
        # spatial = rs.spatial_filter()
        # spatial.set_option(rs.option.holes_fill, 3)
        # filtered_depth = spatial.process(depth_frame)

        # hole_filling = rs.hole_filling_filter()
        # filled_depth = hole_filling.process(filtered_depth)

        # Create colormap to show the depth of the Objects
        colorizer = rs.colorizer()
        depth_colormap = np.asanyarray(colorizer.colorize(depth_frame).get_data())


        depth_image = np.asanyarray(depth_frame.get_data())
        color_image = np.asanyarray(color_frame.get_data())
        if not depth_frame or not color_frame:
            return False, None, None
        return True, depth_frame, depth_image, color_image, depth_colormap

    def release(self):
        self.pipeline.stop()
        
class Jetson_Rover:
    camera_Rover = RoverCamera()
    velocidad = 0
    
    def __init__(self):
        pass
    
    def calc_Velocity(self, distances, time_elapsed):
        pass
    def Voltage(self, error, distance):
        pass
    def Direction(self, error):
        pass
    def draw_Point(self, bgr_frame, depth_frame, distance):
        cv2.circle(bgr_frame,(point[0], point[1]),2,(0,255,0),2)
        cv2.putText(bgr_frame,"{:.3f}m".format(distance), (point[0], point[1]-10),1,2,(0,255,0),2)
        
        cv2.circle(depth_frame,(point[0], point[1]),2,(0,255,0),2)
        cv2.putText(depth_frame,"{:.3f}m".format(distance), (point[0], point[1]-10),1,2,(0,255,0),2)
        
    def init_Rover(self):
        print("Iniciando Rover...")
        
        while(True):
            state, depth_frame, depth_image, color_image, depth_colorMap = self.camera_Rover.get_frames()
            
            if not state:
                print("An error have ocurred, verify the camera conection")
                break
            
            distance = depth_frame.get_distance(point[0], point[1])
            
            distances.append(distance)
                        
            self.draw_Point(color_image, depth_colorMap, distance)
            
            cv2.imshow("Color frame", color_image)
            cv2.imshow("ColorMap", depth_colorMap)
            
            key = cv2.waitKey(1)
            
            if key == 27:
                cv2.destroyAllWindows()
                break


rover = Jetson_Rover()
rover.init_Rover()


