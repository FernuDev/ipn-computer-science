import cv2
import pyrealsense2
from realsense_depth import *
import matplotlib.pyplot as plt

point = (400, 300)

print(tensor.shape)

def show_distance(event, x, y, args, params):
    global point
    point = (x, y)

# Initialize Camera Intel Realsense
dc = DepthCamera()

# Create mouse event
cv2.namedWindow("Color frame")
cv2.setMouseCallback("Color frame", show_distance)

i = 0

depth_frame_plot = np.array([])

while True:
    ret, depth_frame, color_frame= dc.get_frame()
    
    # Show distance for a specific point
    cv2.circle(color_frame, point, 4, (0, 0, 255))
    distance = depth_frame.get_distance(point[1], point[0])
    i+=1

    gray_Color = cv2.cvtColor(color_frame, cv2.COLOR_BGR2GRAY)

    print(f'Depth frame shape: {depth_frame.shape}')
    print(f'Color frame shape: {gray_Color.shape}')

    cv2.putText(color_frame, "{}mm".format(distance), (point[0], point[1] - 20), cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 0), 2)
    cv2.imshow("depth frame", depth_frame)
    cv2.imshow("Color frame", color_frame)
    key = cv2.waitKey(1)
   
    if key == 27:
        break


plt.plot(depth_frame_plot)
