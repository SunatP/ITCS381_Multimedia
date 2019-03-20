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
	double totalb = 0;
	double totalg = 0;
	double totalr = 0;
	double meanb,meang,meanr;
	double mean;
	ofstream fout("filename.txt");
	Mat img = imread("dog.jpg", IMREAD_COLOR);
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			Vec3b color = img.at<Vec3b>(cv::Point(x, y));
			printf("Blue: %d, Green: %d, Red: %d \n ", color[0], color[1], color[2]);
			total += (img.rows + img.cols);
			totalb += (color[0]);
			totalg += (color[1]);
			totalr += (color[2]);
			fout << "Blue Value is: " << (Vec3b)color[0] << "Green Value is: " << (Vec3b)color[1] << "Red Value is: "<< (Vec3b)color[2] << endl; // don't need to cast integer value
		}
	}
	mean = (total / (img.rows * img.cols));
	meanb = (totalb / (img.rows * img.cols));
	meang = (totalg / (img.rows * img.cols));
	meanr = (totalr / (img.rows * img.cols));
	fout << std::fixed << std::setprecision(2) << "The average of BGR value is " << mean << endl; // cast into double value
	fout << std::fixed << std::setprecision(2) << "The average of Blue value is " << meanb << endl; // cast into double value
	fout << std::fixed << std::setprecision(2) << "The average of Green value is " << meang << endl; // cast into double value
	fout << std::fixed << std::setprecision(2) << "The average of Red value is " << meanr << endl; // cast into double value

	fout.close();
	printf("Average of BGR is : %.2f \n", mean);
	printf("Average of Blue Value is : %.2f \n", meanb);
	printf("Average of Green Value is : %.2f \n", meang);
	printf("Average of Red Value is : %.2f \n", meanr);
	printf("Calculate Complete\n");
	cout << "Press Enter to Continue";
	cin.ignore();
	return 0;
}