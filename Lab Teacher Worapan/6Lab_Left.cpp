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
/*
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

}*/

using namespace std;
using namespace cv;


void mouse_callback(int event, int x, int y, int flag, void *param);
int mouse();
int magnitude();
int lab13();
int histogram();
int Lab14();
int act4();
void sobel();
/**
 * @function main
 */
int main()
{
cv:setBreakOnError(true);
	//mouse();
	//sobel();
	//lab13();
	//magnitude();
	//Lab14();
	//act4();
}
void sobel()
{
	Mat img;
	img = imread("dog.jpg", 1);
	namedWindow("Input");
	imshow("Input", img);

	Mat sobel_x, sobel_y;
	Mat abs_sobel_x, abs_sobel_y;

	Mat img_gray;
	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

	//Gradient X
	Sobel(img_gray, sobel_x, CV_16S, 1, 0, 3);
	convertScaleAbs(sobel_x, abs_sobel_x);
	imshow("Sobel X", abs_sobel_x);

	//Gradient Y
	Sobel(img_gray, sobel_y, CV_16S, 0, 1, 3);
	convertScaleAbs(sobel_y, abs_sobel_y);
	imshow("Sobel Y", abs_sobel_y);

	cv::waitKey(0);
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

	return 0;
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

int histogram()
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

int Lab14() {
	Mat img1, hsv1;
	Mat img2, hsv2;

	img1 = imread("dog.jpg", IMREAD_COLOR);
	img2 = imread("dog11.jpg", IMREAD_COLOR);

	cvtColor(img1, hsv1, cv::COLOR_BGR2HSV);
	cvtColor(img2, hsv2, COLOR_BGR2HSV);

	int h_bins = 50; int s_bins = 60;
	int histSize[] = { h_bins, s_bins };

	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };

	const float* ranges[] = { h_ranges,s_ranges };
	int channels[] = { 0,1 };

	MatND hist1;
	MatND hist2;

	calcHist(&hsv1, 1, channels, Mat(), hist1, 2, histSize, ranges, true, false);
	normalize(hist1, hist1, 0, 1, NORM_MINMAX, -1, Mat());
	calcHist(&hsv2, 1, channels, Mat(), hist2, 2, histSize, ranges, true, false);
	normalize(hist2, hist2, 0, 1, NORM_MINMAX, -1, Mat());
	double sim = compareHist(hist1, hist2, cv::HISTCMP_CORREL);
	printf("The correlation similarlity is %f\n", sim);
	printf("\n");
	cin.ignore();
	return 0;
}
int act4()
{
Mat img1, hsv1;
Mat img2, hsv2;
Mat img3, hsv3;

img1 = imread("dog.jpg", IMREAD_COLOR);
img2 = imread("dog_gray.jpg", IMREAD_COLOR);
img3 = imread("dog11.jpg", IMREAD_COLOR);

cvtColor(img1, hsv1, COLOR_BGR2HSV);
cvtColor(img2, hsv2, COLOR_BGR2HSV);
cvtColor(img3, hsv3, COLOR_BGR2HSV);

int h_bins = 50; int s_bins = 60;
int histSize[] = { h_bins, s_bins };

float h_ranges[] = { 0, 180 };
float s_ranges[] = { 0, 256 };

const float* ranges[] = { h_ranges,s_ranges };
int channels[] = { 0,1 };

MatND hist1;
MatND hist2;
MatND hist3;

calcHist(&hsv1, 1, channels, Mat(), hist1, 2, histSize, ranges, true, false);
normalize(hist1, hist1, 0, 1, NORM_MINMAX, -1, Mat());
calcHist(&hsv2, 1, channels, Mat(), hist2, 2, histSize, ranges, true, false);
normalize(hist2, hist2, 0, 1, NORM_MINMAX, -1, Mat());
calcHist(&hsv3, 1, channels, Mat(), hist3, 2, histSize, ranges, true, false);
normalize(hist3, hist3, 0, 1, NORM_MINMAX, -1, Mat());
double sim1 = compareHist(hist1, hist2, HISTCMP_CORREL);
double sim2 = compareHist(hist1, hist3, HISTCMP_CORREL);
printf("The correlation similarlity 1 is %f\n", sim1);
printf("The correlation similarlity 2 is %f\n", sim2);
printf("\n");
cin.ignore();
return 0;
}
