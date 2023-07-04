#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat  img;
vector<vector<int>> newPoints;

vector<vector<int>>myColor{ {10,45,121,56,255,201}, //yellow 
							{153,191,113,179,500,255} }; //Pink


vector<Scalar>myColorValue{ {0,255,255}, //yellow 
						    {255,0,255}}; //Pink


Point getCotours(Mat imgDil) {
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	Point myPoint(0, 0);
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		vector<vector<Point>>conPoly(contours.size());
		vector<Rect>boundRect(contours.size());
		string objType;

		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

		
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

 
		}
	}
	return myPoint;
}


vector<vector<int>> findColor(Mat img) {


	Mat  imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < myColor.size(); i++)
	{
		Scalar lower(myColor[i][0], myColor[i][1], myColor[i][2]);
		Scalar upper(myColor[i][3], myColor[i][4], myColor[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		imshow(to_string(i), mask);
		Point myPoint = getCotours(mask);
		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x, myPoint.y,i });
		}
	}
	return newPoints;
}

void drawPoints(vector<vector<int>> newPoints, vector<Scalar>myColorValue) {

	for (int i = 0; i < newPoints.size(); i++) {
	
		circle(img, Point(newPoints[i][0],newPoints[i][1]),10,myColorValue[newPoints[i][2]], FILLED);
	}
}


void main() {
	VideoCapture video(0);
	//CascadeClassifier facedetect;
	//Mat img;
	//facedetect.load("haarcascade_frontalface_default.xml");

	while (true) {
		video.read(img);
		newPoints=findColor(img);
		drawPoints(newPoints, myColorValue);

		imshow("Frame", img);
		waitKey(1);


	}
}