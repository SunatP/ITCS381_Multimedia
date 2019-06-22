/*
	Code By
	Sunat P. 6088130
	Barameerak K. 6088156
	Poonkasem K. 6088071

	Teacher Assf. Prof. Dr. Worapan K.
*/
#include<stdio.h>
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdlib.h>
#include<math.h>

using namespace std;
using namespace cv;

// Using Forward Seam Carving not Backward Seam Carving
int main()
{
	// Create Matrix img
	Mat img = imread("test.jpg");
	namedWindow("Original", WINDOW_AUTOSIZE); // Create Windows to display img
	imshow("Original", img);
	int c = cvWaitKey(0);
	Size sz = img.size(); // Create sz for specify width and height of image
	int height = sz.height;
	int width = sz.width;
	int bsstartpoint, next;
	int cl, cu, cr; // initialize value for CL , CU , CR
	Mat FWDseamcrav; // Create Matrix to calculate value in new img

	// ESC or Escape = 27, A = 97 , D = 100 , S = 115 , W = 119 
	while (c != 27)
	{
		while (c != 97 && c != 100 && c != 115 && c != 119 && c != 27)
		{ // Wait until press WASD key
			c = cvWaitKey(0);
		}
		if (c == 97 || c == 100) { // A = 97 For Reduce width in vertical directional & D = 100 for Increase width in Vertical directional
			/* Code Here */
			cv::Mat gray_img; // Create Matrix name grey_img for convert color img to grey img
			cvtColor(img, gray_img, cv::COLOR_BGR2GRAY); // used cvtColor() or convertColor from original to grey img by using cv::COLOR_BGR2GRAY
			cv::Size csz = gray_img.size();
			cv::Mat M(csz.height, csz.width, CV_8U); // Create Matrix M
			cv::Mat K(csz.height, csz.width, CV_8U); // Create Matrix K
										  // CV_8U is 8-bit unsigned integer matrix/image with 3 channels
			for (int i = 0; i < gray_img.rows; i++) // Create 2 for loop for calculate Seam Carving by using Forward Seam Carving
			{
				for (int j = 0; j < gray_img.cols; j++)
				{
					if (i == 0)
					{
						if (j == 0)
						{
							M.at<uchar>(Point(j, i)) = abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j, i))); // Calculate M matrix
							K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
						}
						else if (j == gray_img.cols - 1)
						{
							M.at<uchar>(Point(j, i)) = abs(gray_img.at<uchar>(Point(j, i)) - gray_img.at<uchar>(Point(j - 1, i))); // Calculate M matrix
							K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
						}
						else
						{
							M.at<uchar>(Point(j, i)) = abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j - 1, i))); // Calculate M matrix
							K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
						}
					}
					else
					{
						if (j == 0)
						{
							cu = M.at<uchar>(Point(j, i - 1)) + abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j, i))); // Calculate CU Position
							cr = M.at<uchar>(Point(j + 1, i)) + (abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j, i))) + abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j + 1, i)))); // Calcualte CR Position
							M.at<uchar>(Point(j, i)) = min(cu, cr);  // M matrix value is equal from calculate CU , CR by using min()
							if (M.at<uchar>(Point(j, i)) == cu)  // M matrix value equal to CU
							{
								K.at<uchar>(Point(j, i)) = 2;  // Value of K Matrix will equal to 2
							}
							else {
								K.at<uchar>(Point(j, i)) = 3; // Value of K Matrix will equal to 3
							}

						}
						else if (j == gray_img.cols - 1) {
							cl = M.at<uchar>(Point(j - 1, i - 1)) + (abs(gray_img.at<uchar>(Point(j, i)) - gray_img.at<uchar>(Point(j - 1, i))) + abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j - 1, i)))); // Calculate CL Position
							cu = M.at<uchar>(Point(j, i - 1)) + abs(gray_img.at<uchar>(Point(j, i)) - gray_img.at<uchar>(Point(j - 1, i))); // Calculate CU Postion
							M.at<uchar>(Point(j, i)) = min(cl, cu); // M matrix value is equal from calculate CL , CU by using min()
							if (M.at<uchar>(Point(j, i)) == cu)  // M matrix value equal to CU
							{
								K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
							}
							else
							{
								K.at<uchar>(Point(j, i)) = 1; // Value of K Matrix will equal to 1
							}

						}
						else
						{
							cl = M.at<uchar>(Point(j - 1, i - 1)) + (abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j - 1, i))) + abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j - 1, i)))); // Calculate CL position
							cu = M.at<uchar>(Point(j, i - 1)) + abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j - 1, i))); // Calculate CU position
							cr = M.at<uchar>(Point(j + 1, i - 1)) + (abs(gray_img.at<uchar>(Point(j + 1, i)) - gray_img.at<uchar>(Point(j - 1, i))) + abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j + 1, i)))); // Calculate CR position
							M.at<uchar>(Point(j, i)) = min({ cl,cu,cr });
							if (M.at<uchar>(Point(j, i)) == cu) // If M matrix value equal to CU
							{
								K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
							}
							else if (M.at<uchar>(Point(j, i)) == cr)
							{
								K.at<uchar>(Point(j, i)) = 3; // Value of K Matrix will equal to 3
							}
							else
							{
								K.at<uchar>(Point(j, i)) = 1; // Value of K Matrix will equal to 1
							}

						}
					}
				}
			}

			//namedWindow("Energy Map", WINDOW_AUTOSIZE);
			//imshow("Energy Map", M); // Show Energy Map

			// Find the Best Seam in the Vertical direction

			// Start to find min value from last row to start find best seam

			int startbestseam = M.at<uchar>(Point(0, gray_img.rows - 1)); // Start from 0 gray_img cols and rows 
			for (int b = 0; b < gray_img.cols; b++)
			{
				if (M.at<uchar>(Point(b, gray_img.rows - 1)) < startbestseam) // if b value in M matrix is less than startbestseam  
				{
					startbestseam = M.at<uchar>(Point(b, gray_img.rows - 1)); // startbestseam value is equal to M matrix
					bsstartpoint = b; // Best seam point will equal to b value
				}
			}
			Mat BSseam(csz.height, csz.width, CV_8U, Scalar(0, 0, 0)); // Create matrix name BSseam
			FWDseamcrav = BSseam.clone(); // FWDseamcarv matrix will equal to BSseam that clone value into new matrix
			next = bsstartpoint;
			for (int c = gray_img.rows - 1; c > 0; c--)
			{
				FWDseamcrav.at<uchar>(Point(next, c)) = 255; // FWDseamcarv set value to 255
				if (K.at<uchar>(Point(next, c)) == 1) // If K matrix value equal to 1
				{
					next = next - 1;
				}
				else if (K.at<uchar>(Point(next, c)) == 2) // If K matrix value equal to 2
				{
					next = next;
				}
				else
				{
					next = next + 1;
				}
			}
			//namedWindow("Best Seam", WINDOW_AUTOSIZE);
			//imshow("Best Seam", FWDseamcrav); // Show Best seam Output 
			gray_img.release();
			M.release();
			K.release();

		}
		if (c == 115 || c == 119) // S Key for decrease height horizontal directional and W Key for increase height horizontal directical
		{
			/* CODE HERE */
			Mat gray_img; // Create Matrix for gray img
			cvtColor(img, gray_img, COLOR_BGR2GRAY); // Convert normal color into gray color
			Size csz = gray_img.size(); // Declare size name csz 
			Mat M(csz.height, csz.width, CV_8U);
			Mat K(csz.height, csz.width, CV_8U);
			for (int j = 0; j < gray_img.cols; j++)
			{
				for (int i = 0; i < gray_img.rows; i++)
				{
					if (j == 0)
					{
						if (i == gray_img.rows - 1)
						{
							M.at<uchar>(Point(j, i)) = abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i))); // Calculate M matrix
							K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
						}
						else if (i == 0)
						{
							M.at<uchar>(Point(j, i)) = abs(gray_img.at<uchar>(Point(j, i)) - gray_img.at<uchar>(Point(j, i + 1))); // Calculate M matrix
							K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
						}
						else
						{
							M.at<uchar>(Point(j, i)) = abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i + 1))); // Calculate M matrix
						}
					}
					else
					{
						if (i == gray_img.rows - 1)
						{
							cu = M.at<uchar>(Point(j - 1, i)) + abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i))); // Calculate value for CU
							cr = M.at<uchar>(Point(j - 1, i - 1)) + (abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i))) + abs(gray_img.at<uchar>(Point(j - 1, i)) - gray_img.at<uchar>(Point(j, i - 1)))); // Calculate value for CR
							if (M.at<uchar>(Point(j, i)) == cu) // If M matrix value equal to CU
							{
								K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
							}
							else
							{
								K.at<uchar>(Point(j, i)) = 3; // Value of K Matrix will equal to 3
							}
						}
						else if (i == 0)
						{
							cl = M.at<uchar>(Point(j - 1, i + 1)) + (abs(gray_img.at<uchar>(Point(j, i)) - gray_img.at<uchar>(Point(j, i + 1))) + abs(gray_img.at<uchar>(Point(j - 1, i)) - gray_img.at<uchar>(Point(j, i + 1)))); // Calculate value for CL
							cu = M.at<uchar>(Point(j - 1, i)) + abs(gray_img.at<uchar>(Point(j, i)) - gray_img.at<uchar>(Point(j, i + 1))); // Calculate value for CU
							M.at<uchar>(Point(j, i)) = min({ cl,cu });
							if (M.at<uchar>(Point(j, i)) == cu) // If M matrix value equal to CU
							{
								K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
							}
							else
							{
								K.at<uchar>(Point(j, i)) = 1; // Value of K Matrix will equal to 1
							}
						}
						else
						{
							cl = M.at<uchar>(Point(j - 1, i + 1)) + (abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i + 1))) + abs(gray_img.at<uchar>(Point(j - 1, i)) - gray_img.at<uchar>(Point(j, i + 1)))); // Calculate value for CL
							cu = M.at<uchar>(Point(j - 1, i)) + abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i + 1))); // Calculate value for CU
							cr = M.at<uchar>(Point(j - 1, i - 1)) + (abs(gray_img.at<uchar>(Point(j, i - 1)) - gray_img.at<uchar>(Point(j, i + 1))) + abs(gray_img.at<uchar>(Point(j - 1, i)) - gray_img.at<uchar>(Point(j, i - 1)))); // Calculate value for CR
							M.at<uchar>(Point(j, i)) = min({ cl,cu,cr });
							if (M.at<uchar>(Point(j, i)) == cu) // If M matrix value equal to CU
							{
								K.at<uchar>(Point(j, i)) = 2; // Value of K Matrix will equal to 2
							}
							else if (M.at<uchar>(Point(j, i)) == cr)
							{
								K.at<uchar>(Point(j, i)) = 3; // Value of K Matrix will equal to 3
							}
							else
							{
								K.at<uchar>(Point(j, i)) = 1; // Value of K Matrix will equal to 1
							}
						}
					}
				}
			}
			//namedWindow("Energy Map", WINDOW_AUTOSIZE);
			//imshow("Energy Map", M); // Show Energy Map

			// Find the best seam in the vertical direction
			int startbestseam = M.at<uchar>(Point(gray_img.cols - 1, 0));
			int bsstartpoint, next;
			bsstartpoint = 0;
			next = 0;
			for (int b = 0; b < gray_img.rows; b++)
			{
				if (M.at<uchar>(Point(gray_img.cols - 1, b)) < startbestseam)
				{
					startbestseam = M.at<uchar>(Point(gray_img.cols - 1, b)); // startbestseam equal to M matrix
					bsstartpoint = b;  // Set bsstartpoint equal to b 
				}
			}
			Mat FWDBSeam(csz.height, csz.width, CV_8U, Scalar(0, 0, 0)); // Create Matrix for calculate Forward seam carving
			FWDseamcrav = FWDBSeam.clone(); // Clone matrix FWDBSeam to FWDseamcrav
			next = bsstartpoint; // Set next equal to bsstartpoint
			for (int c = gray_img.cols - 1; c > 0; c--)
			{
				FWDseamcrav.at<uchar>(Point(c, next)) = 255; // Matrix FWDseamcrav set to 255
				if (K.at<uchar>(Point(c, next)) == 1)
				{
					next = next + 1; // Increment value by plus 1
				}
				else if (K.at<uchar>(Point(c, next)) == 2)
				{
					next = next; // No change value
				}
				else {
					next = next - 1; // Decrement value by minus 1 
				}
			}
			//namedWindow("Best Seam", WINDOW_AUTOSIZE);
			//imshow("Best Seam", FWDseamcrav);
			gray_img.release();
			M.release();
			K.release();
		}

		// Insert or delete the best seam
		if (c == 97)  // A key
		{
			// Reduce width or delete seam vertically
			// Copy the pixels into this image
			Mat img_new(height, --width, CV_8UC3, Scalar(0, 0, 0));  // Create new Matrix for new img
			int del;
			for (int i = 0; i < img_new.rows; i++)
			{
				del = 0;
				for (int j = 0; j < img_new.cols; j++)
				{
					if (FWDseamcrav.at<uchar>(Point(j, i)) == 255) // If FWDseamcrav is equal to 255
					{
						del = 1; // Set del equal to 1
					}
					if (del == 1)
					{

						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j + 1, i));  // Set img_new Matrix will increment value in Point j + 1 
					}
					else
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j, i)); // img_new will equal to original img Matrix
					}
				}
			}
			// Show the resized image
			imshow("Output", img_new);
			// Clone img new into img for next loop processing
			img.release();
			img = img_new.clone();
			img_new.release();
		}
		if (c == 100) // D
		{
			// Increase width or insert seam vertically
			// Copy the pixels into this image
			Mat img_new(height, ++width, CV_8UC3, Scalar(0, 0, 0));
			int ins;
			for (int i = 0; i < img_new.rows; i++)
			{
				ins = 0;
				for (int j = 0; j < img_new.cols - 1; j++)
				{
					if (ins == 1)
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j - 1, i)); // Set img_new Matrix will decrement value in Point j - 1 
					}
					else
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j, i)); // img_new will equal to original img Matrix
					}
					if (FWDseamcrav.at<uchar>(Point(j, i)) == 255) // If FWDseamcrav is equal to 255
					{
						ins = 1; // Set ins equal to 1
					}
				}
			}
			// Show the resized image
			imshow("Output", img_new);
			// Clone img new into img for next loop processing
			img.release();
			img = img_new.clone();
			img_new.release();
		}
		if (c == 115)
		{
			// Reduce height or delete seam horizontal
			// Copy the pixels into this image
			Mat img_new(--height, width, CV_8UC3, Scalar(0, 0, 0));
			int del;
			for (int j = 0; j < img_new.cols; j++)
			{
				del = 0;
				for (int i = 0; i < img_new.rows; i++)
				{
					if (FWDseamcrav.at<uchar>(Point(j, i)) == 255) // If FWDseamcrav is equal to 255
					{
						del = 1; // Set del equal to 1
					}
					if (del == 1)
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j, i + 1)); // Set img_new Matrix will increment value in Point i + 1 
					}
					else
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j, i)); // img_new will equal to original img Matrix
					}
				}
			}
			// Show the resized image
			imshow("Output", img_new);
			// Clone img)new into img for next loop processing
			img.release();
			img = img_new.clone();
			img_new.release();
		}
		if (c == 119)
		{
			// Increase height or insert seam horizontal
			// Copy the pixels into this image
			Mat img_new(++height, width, CV_8UC3, Scalar(0, 0, 0));
			int ins;
			for (int j = 0; j < img_new.cols; j++)
			{
				ins = 0;
				for (int i = 0; i < img_new.rows - 1; i++)
				{
					if (ins == 1)
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j, i - 1));   // Set img_new Matrix will decrement value in Point i + 1 
					}
					else
					{
						img_new.at<Vec3b>(Point(j, i)) = img.at<Vec3b>(Point(j, i));  // img_new will equal to original img Matrix
					}
					if (FWDseamcrav.at<uchar>(Point(j, i)) == 255)
					{
						ins = 1;
					}
				}
			}
			// Show the resized image
			imshow("Output", img_new);
			// Clone img new into img for next loop processing
			img.release();
			img = img_new.clone();
			img_new.release();
		}
		if (c == 27)
			break;
		c = cvWaitKey(0);
	}
	return 0;
}