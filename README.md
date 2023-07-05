# Original-Virtual-Painter
This C++ program, leveraging the OpenCV library, identifies and tracks yellow and pink markers in a live video feed, allowing users to draw with these colors. It applies image processing techniques to detect the markers' contours, draw circles around them in their respective colors, and continuously updates their positions in real-time. This project showcases practical applications of computer vision and image processing, demonstrating the ability to track objects of specific colors and enable interactive drawing using those markers. It highlights skills in image manipulation, contour detection, and real-time video processing, making it a valuable addition to a portfolio focused on computer vision and graphics programming.


**Description**


The Color Marker Tracker program utilizes the OpenCV library to detect and track yellow and pink markers in a live video feed. The program performs the following steps:

Video Capture: The program accesses the video feed from a connected camera.

Color Detection: The program converts each frame of the video to the HSV color space and applies a color range to filter out yellow and pink markers. It creates binary masks for the detected colors.

Contour Detection: The program finds contours in the binary masks to identify the markers' positions. It filters out small contours based on their area and approximates the contours' shapes.

Tracking and Drawing: The program tracks the markers by determining the center point of each contour. It then draws circles around the markers using their respective colors.

Display: The program displays the video feed with the markers and circles drawn in real-time.

Continuous Update: The program continuously updates the markers' positions and redraws the circles as the markers move within the video feed.

**Features**

Real-time tracking and drawing with yellow and pink markers in a live video feed.
Conversion of video frames to the HSV color space for color detection.
Detection of contours and filtering based on contour area.
Approximation of contour shapes to find the markers' center points.
Drawing circles around the markers using their respective colors.
Continuous updates of marker positions and circles in real-time.


**Installation**

Clone the repository:
Navigate to the project directory:
cd ColorMarkerTracker
Compile the program using a C++ compiler and link with OpenCV libraries:

**Usage**
Run the program, and it will access the video feed from the connected camera.
The program will detect yellow and pink markers in the live video feed.
As you move the yellow and pink markers within the camera's view, the program will track their positions and draw circles around them using their respective colors.
The drawn circles will be updated in real-time based on the markers' movements.
Enjoy the interactive drawing experience using the yellow and pink markers.
Press the 'Esc' key to exit the program.

License
This project is licensed under the MIT License.

**Contribution**
Contributions to the Color Marker Tracker project are welcome. Feel free to fork the repository and submit pull requests with your improvements.

If you find any issues or have suggestions for enhancements, please create an issue in the GitHub repository.

**Acknowledgments**
The Color Marker Tracker project showcases the capabilities of OpenCV in real-time color detection, contour analysis, and interactive drawing. It demonstrates practical applications of computer vision and image processing in tracking objects of specific colors and enabling interactive experiences.

<img width="283" alt="ohui" src="https://github.com/VardanKeshishyan/Original-Virtual-Painter/assets/138354187/438ac636-5768-4260-8f0b-15618dee2608">


<img width="1101" alt="hfdh" src="https://github.com/VardanKeshishyan/Original-Virtual-Painter/assets/138354187/fea20ffe-75a3-409a-935c-288ea62ce762">
