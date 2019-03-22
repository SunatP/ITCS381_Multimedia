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
	Mat image = imread("dog.jpg", 1);
	namedWindow("Original Image", 1);
	imshow("Original Image", image);

	// Split the image into different channels
	vector<Mat> rgbChannels(3);
	split(image, rgbChannels);

	// Show individual channels
	Mat g, fin_img;
	g = Mat::zeros(Size(image.cols, image.rows), CV_8UC1);

	// Showing Red Channel
	// G and B channels are kept as zero matrix for visual perception
	{
		vector<Mat> channels;
		channels.push_back(g);
		channels.push_back(g);
		channels.push_back(rgbChannels[2]);

		// Merge the three channels
		merge(channels, fin_img);
		namedWindow("Red", 1);
		imshow("Red", fin_img);
	}

	// Showing Green Channel
	{
		vector<Mat> channels;
		channels.push_back(g);
		channels.push_back(rgbChannels[1]);
		channels.push_back(g);
		merge(channels, fin_img);
		namedWindow("Green", 1);
		imshow("Green", fin_img);
	}

	// Showing Blue Channel
	{
		vector<Mat> channels;
		channels.push_back(rgbChannels[0]);
		channels.push_back(g);
		channels.push_back(g);
		merge(channels, fin_img);
		namedWindow("Blue", 1);
		imshow("Blue", fin_img);
	}
	cv::waitKey(0);

}