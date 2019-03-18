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

	double total = 0;
	double mean;
	ofstream fout("filename.txt");
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			int color = img.at<uchar>(cv::Point(x, y));
			printf("Grey: %d\n", color);
			total += (img.rows+img.cols);
			fout << "Gray Value is:  " << (int)color << endl; // don't need to cast integer value
		}
	}
	 mean = (total / (img.rows * img.cols));
	 fout << std::fixed << std::setprecision(2) << "The average of Gray value is " <<(double)mean << endl; // cast into double value
	 fout.close();
	printf("Average of Gray is : %.2f \n", mean);
	printf("Calculate Complete\n");
	cout << "Press Enter to Continue";
	cin.ignore();
	return 0;
}