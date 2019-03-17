#include<stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cmath>
#include<fstream>

using namespace std;
using namespace cv;

int main()
{

	double total = 0;
	double mean;
	ofstream fout("filename.txt");
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			int color = img.at<uchar>(cv::Point(x, y));
			printf("Grey: %d\n", color);
			total += (img.rows+img.cols);
			fout << (char)color << " " << color << endl; // don't need to cast int to int
		}
	}

	 mean = (total / (img.rows * img.cols));
	 fout << (char)mean << " " << mean << endl; // don't need to cast int to int
	 fout.close();
	printf("Average of Gray is : %f ", mean);
	return 0; 
}