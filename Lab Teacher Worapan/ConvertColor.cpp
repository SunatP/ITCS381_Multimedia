#include<stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("dog.jpg", 1);
	imshow("Example-In", img);

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	imshow("Example-Out", gray);
	imwrite("dog_gray.jpg", gray);
	cv::waitKey(0);

	return 0 ;



}