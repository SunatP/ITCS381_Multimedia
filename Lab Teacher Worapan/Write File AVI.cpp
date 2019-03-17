#include<stdio.h>
#include<opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/videoio/videoio.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{

	VideoCapture cap("./20.avi");


	if (!cap.isOpened())
	{
		cout << "Error opening video stream" << endl;
		return -1;
	}
	int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("20_out.avi", cv::CAP_PROP_FOURCC>>('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));

	while (true)
	{
		Mat frame;
		cap >> frame;  // take new frame from camera
		//End of video
		if (frame.empty())
			break;	
		
		video.write(frame);
		
		imshow("Frame", frame);
		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}
	cap.release();
	video.release();
	destroyAllWindows();
}