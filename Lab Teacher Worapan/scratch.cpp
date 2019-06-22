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


void mouse_callback(int event, int x, int y, int flag, void *param);
int mouse();
int magnitude();
int lab13();
/**
 * @function main
 */
int main()
{
	cv::setBreakOnError(true);
	magnitude();
}
int magnitude()
{

	Mat img = imread("dog.jpg", IMREAD_COLOR);
	namedWindow("Input");

	Mat sobelX, sobelY, abssobelX, abssobelY, imgrey;
	cv::Mat1f mag;
	cv::cvtColor(img, imgrey, COLOR_BGR2GRAY);

	cv::Sobel(imgrey, sobelX, CV_32F, 1, 0, 3);
	cv::convertScaleAbs(sobelX, abssobelX);
	namedWindow("SobelX");
	cv::imshow("SobelX", abssobelX);

	cv::Sobel(imgrey, sobelY, CV_32F, 0, 1, 3);
	cv::convertScaleAbs(sobelY, abssobelY);
	namedWindow("SobelY");
	cv::imshow("SobelY", abssobelY);

	magnitude(sobelX, sobelY, mag);
	imshow("Result", mag);

	cv::waitKey(0);

	return 0 ;
}


int lab13()
{
	Mat src, dst;

	/// Load image
	src = imread("dog.jpg", IMREAD_COLOR);

	if (!src.data)
	{
		return -1;
	}

	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	/// Display
	namedWindow("calcHist Demo", cv::WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);

	waitKey(0);

	return 0;
}


int mouse()
{

	Mat img;
	img = imread("dog.jpg", 1);

	namedWindow("Example");
	setMouseCallback("Example", mouse_callback);

	imshow("Example", img);
	waitKey(0);
	return 0;

}

void mouse_callback(int event, int x, int y, int flag, void *param)
{
	if (event == EVENT_MOUSEMOVE)
	{
		cout << "( X: " << x << ", Y: " << y << ")" << endl;
	}
	if (event == EVENT_LBUTTONDOWN)
	{
		Mat img;
		img = imread("dog.jpg", 1);
		Vec3b color = img.at<Vec3b>(cv::Point(x, y));

		cout << "Left button of the mouse is clicked - position ( X:" << x << ", Y: " << y << ")" << endl;
		printf("Blue: %d, Green: %d, Red: %d \n", color[0], color[1], color[2]);
	}
}
