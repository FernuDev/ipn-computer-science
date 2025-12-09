import cv2
import pyrealsense2 as rs
import numpy as np

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

        colorizer = rs.colorizer()
        depth_colormap = np.asanyarray(colorizer.colorize(depth_frame).get_data())


        depth_image = np.asanyarray(depth_frame.get_data())
        color_image = np.asanyarray(color_frame.get_data())
        if not depth_frame or not color_frame:
            return False, None, None
        return True, depth_frame, depth_image, color_image, depth_colormap

    def release(self):
        self.pipeline.stop()
        

#Cargando la camara con una libreria externa
Camera = RoverCamera()

while True:

	#Obteniendo la informacion necesaria de la camara
	status, depth_frame, depth_img, color_img, depth_colormap = Camera.get_frames()
	
	point_X, point_Y = 250, 250
	distance_mm = depth_frame.get_distance(point_X, point_Y)

	cv2.circle(color_img, (point_X, point_Y), 4, (0,255,0), 2)
	cv2.putText(color_img, "{:.3f} mm".format(distance_mm), (point_X, point_Y-10), 0, 1, (0,0,255), 2)

	# print(f'Distance to the point 100,250: {distance_mm}')

	#Mostrando los frames de la camara BGR
	cv2.imshow("Bgr frame", color_img)
	cv2.imshow("Depth frame", depth_img)
	key = cv2.waitKey(1)

	#Mostrando los datos de profundidad
	# print(depth_frame)

	if key == 27:
		cv2.destroyAllWindows()
		break