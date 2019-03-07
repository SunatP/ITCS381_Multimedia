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

	Size size(300,300);
	Mat img = imread("dog.jpg", 1);
	imshow("Example-In", img);

	Mat out; // Using Gaussian Tech. => blur , GBlur , MBlur , biBlur
	resize(img, out, size);
	imshow("Example-Out", out);

	cv::waitKey(0);

}


