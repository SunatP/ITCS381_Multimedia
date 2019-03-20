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
	namedWindow("Input");
	imshow("Input", img);

	Mat sobel_x, sobel_y;
	Mat abs_sobel_x, abs_sobel_y;

	Mat img_gray;
	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

	//Gradient X
	Sobel(img_gray,sobel_x,CV_16S,1,0,3);
	convertScaleAbs(sobel_x,abs_sobel_x);
	imshow("Sobel X", abs_sobel_x);

	//Gradient Y
	Sobel(img_gray, sobel_y, CV_16S, 0, 1, 3);
	convertScaleAbs(sobel_y, abs_sobel_y);
	imshow("Sobel Y", abs_sobel_y);

	cv::waitKey(0);
}