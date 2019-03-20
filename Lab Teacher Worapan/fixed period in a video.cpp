#include<stdio.h>
#include<opencv2/core/core.hpp>
#include"opencv2/opencv.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/videoio/videoio.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {

	time_t start, end;
	VideoCapture cap("./20.avi");

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}
	int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("20out.avi", cv::CAP_PROP_FOURCC>>('M', 'J', 'P', 'G'), 30, Size(frame_width, frame_height), true);
	time(&start);

	for (;;) { // interval loop with time 

		Mat frame;
		cap >> frame;
		video.write(frame);
		imshow("Frame", frame);
		char c = (char)waitKey(33);
		if (c == 27) break;

		time(&end);
		double dif = difftime(end, start);
		printf("Elasped time is %.2lf seconds. \n", dif);
		if (dif >= 18) // 18 second interval * 30 fps = 540 fps or 10 seconds output it's mean 5.4 frames per 1 second average should be 5.1 ~ 5.8 fps
		{ // dif in second not millisecond
			std::cout << "DONE" << dif << std::endl; // standard output when complete
			break;
		}

	}
	return 0;
}