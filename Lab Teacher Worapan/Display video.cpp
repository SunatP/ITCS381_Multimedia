#include<stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap("kimiwa.avi");
	if (!cap.isOpened())
	{
		return -1;
	}
	while (1)
	{
		Mat frame;
		cap >> frame;  // take new frame from camera
		//End of video
		if (frame.empty())
		{
			break; 
		}
		imshow("Frame", frame);

		char c = (char)waitKey(25);
		if (c == 27)  // 27 is ASCII for 'ESC' button
			break;
	}
	cap.release();
	destroyAllWindows();
}