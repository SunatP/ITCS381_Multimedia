#include<stdio.h> // Standard io
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream> // for output
#include <cmath> // Calculate mathmatic
#include<fstream> // Write file output
#include <windows.h> // Add this header for waiting output before close automatically
#include <iomanip> // add for decimal place
#include <limits>


using namespace std;
using namespace cv;

void mouse_callback(int event, int x, int y, int flag, void *param);

int main()
{

	Mat img;
	img = imread("dog.jpg", 1);

	namedWindow("Example");
	setMouseCallback("Example", mouse_callback);

	imshow("Example", img);
	waitKey();
	
}

void mouse_callback(int event, int x, int y, int flag, void *param)
{
	if (event == EVENT_MOUSEMOVE)
	{
		cout << "( X: " << x << ", Y: " << y << ")" << endl;
	}
	if (event == EVENT_LBUTTONDOWN)
	{
		Mat img;
		img = imread("dog.jpg", 1);
		Vec3b color = img.at<Vec3b>(cv::Point(x, y));
		
		cout << "Left button of the mouse is clicked - position ( X:" << x << ", Y: " << y << ")" << endl;
		printf("Blue: %d, Green: %d, Red: %d \n", color[0], color[1], color[2]);
	}
}