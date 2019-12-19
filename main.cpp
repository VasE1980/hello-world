/*
 * main.cpp
 *
 *  Created on: 2019.12.19
 *      Author: V
 */

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat image;
	if (argc == 2)
	{
		image = imread(argv[1], 1);   // Read the file
	}
	else
	{
		image = imread("worldmap.png", 1);   // Read the file
	}
	if (!image.data)                              // Check for invalid input
	{
		std::cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat mask;
	mask = imread("mask.png", 1);   // Read the file
	if (!mask.data)                              // Check for invalid input
	{
		std::cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	namedWindow("Hello World!", WINDOW_AUTOSIZE);	  // Create a window for display.

	imshow("Hello World!", image);                  // Show our image inside it.
	waitKey(100);                                       // Wait for a keystroke in the window

	resize(mask, mask, cv::Size(image.cols, image.rows));

	image += mask;
	
	imshow("Hello World!", image);                  // Show our image inside it.
	waitKey(0);                                       // Wait for a keystroke in the window

	return 0;
}

