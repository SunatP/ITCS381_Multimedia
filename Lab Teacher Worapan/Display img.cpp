#include<stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#define MODE 1

int main()
{
	if (MODE == 1)
	{
		Mat img;
		img = imread("dog.jpg", 1);
		namedWindow("Display window", WINDOW_AUTOSIZE);
		imshow("Display Window", img);
		waitKey(0);
	}
	return 0;
}
