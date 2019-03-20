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

int main()
{
	String text = " ";
	int FontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double FontScale = 2;
	int thickness = 3;
	Mat img(600, 600, CV_8UC3, Scalar(0,0,255));

	int baseline = 0;
	Size textSize = getTextSize(text, FontFace, FontScale, thickness, &baseline);

	baseline += thickness;

	Point textOrg((img.cols - textSize.width) / 2, (img.rows + textSize.height) / 2);

	cv::rectangle(img, textOrg + Point(25, 100), textOrg + Point(textSize.width - textSize.height),Scalar(128,64,0), cv::FILLED);
	cv::circle(img, textOrg + Point(8, -25), 25,Scalar(64, 128, 0), cv::FILLED);

	cv::line(img, textOrg + Point(-50, -100), textOrg + Point(textSize.width - textSize.height), Scalar(128, 64, 0));	
	cv::putText(img, text, textOrg, FontFace, FontScale, Scalar(0, 0, 255), 8);

	cv::line(img, textOrg + Point(85, 100), textOrg + Point(textSize.width - textSize.height), Scalar(128, 64, 0));


	
	imshow("Example", img);

	cv::waitKey(0);
}