#include<stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

int main()
{
	namedWindow("Example-In");
	namedWindow("Example-Out");

	Mat img = imread("dog.jpg", 1);
	imshow("Example-In", img);

	Mat out; // Using Gaussian Tech. => blur , GBlur , MBlur , biBlur
	GaussianBlur(img, out, Size(7, 7), 0, 0);
	imshow("Example-Out", out);

	cv::waitKey(0);

}


