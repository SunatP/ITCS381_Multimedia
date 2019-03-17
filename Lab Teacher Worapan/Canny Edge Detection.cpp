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

	Mat img_blur, out; // Using Gaussian Tech. => blur , GBlur , MBlur , biBlur
	blur(img, img_blur, Size(5, 5));

	int lowthres = 20; /* Low Value for limit with 25% average value of img*/
	int highthres = 60; /* High Value for limit with 25% average value of img*/
	int kernel_size = 3; /* used for find image gradients */
	Canny(img_blur,out,lowthres,highthres,kernel_size);

	imshow("Example-Out", out);

	cv::waitKey(0);

}


