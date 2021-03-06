#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "tennis_ball_detection.h"

using namespace cv;
using namespace std;

int main() {
	VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.
	VideoCapture stream2(1);

	if (!stream1.isOpened()) { //check if video device has been initialised
		cout << "cannot open webcam stream ";
	}
	if (!stream2.isOpened()) { //check if video device has been initialised
		cout << "cannot open external cam stream";
	}

	/*
	//unconditional loop
	while (true) {
		Mat cameraFrame;
		stream1.read(cameraFrame);
		Rect croppedRect = Rect(0, 0, cameraFrame.cols / 2, cameraFrame.rows);
		cameraFrame = cameraFrame(croppedRect);
		findTennisBall(cameraFrame);
		imshow("cam", cameraFrame);
		if (waitKey(30) >= 0)
		{
			break;
		}

		cout << cameraFrame.rows << " "  << cameraFrame.cols << endl;

		Mat cameraFrame2;
		//cameraFrame2 = imread("dog_and_ball.jpg");
		stream2.read(cameraFrame2);
		findTennisBall(cameraFrame2);
		/*imshow("cam2", cameraFrame2);
		if (waitKey(30) >= 0)
			break;*/
	/*
		Mat padded;
		Mat padded2;
		int rowPadding1 = 0;
		int colPadding1 = 0;
		int rowPadding2 = 0;
		int colPadding2 = 0;
		if (cameraFrame.rows > cameraFrame2.rows)
		{
			rowPadding2 = cameraFrame.rows - cameraFrame2.rows;
		}
		else
		{
			rowPadding1 = cameraFrame2.rows - cameraFrame.rows;
			//cout << "here" << endl;
		}
		if (cameraFrame.cols > cameraFrame2.cols)
		{
			colPadding2 = cameraFrame.cols - cameraFrame2.cols;
			//cout << "here 2" << endl;
		}
		else
		{
			colPadding1 = cameraFrame2.cols - cameraFrame.cols;
		}
		copyMakeBorder(cameraFrame2, padded2, 0, rowPadding2, 0, colPadding2, BORDER_CONSTANT, Scalar::all(0));
		copyMakeBorder(cameraFrame, padded, 0, rowPadding1, 0, colPadding1, BORDER_CONSTANT, Scalar::all(0));
		//imshow("cam2", padded);
		/*if (waitKey(30) >= 0)
			break;*/

		/*cout << padded.rows << " " << padded2.rows << " " << padded.cols << " " << padded2.cols << endl;
		//Mat new1;
		//Mat new2;
		Mat combined;
		//resize(cameraFrame, new1, Size(300, 300), 0, 0, INTER_CUBIC);
		//resize(cameraFrame2, new2, Size(300, 300), 0, 0, INTER_CUBIC);
		//hconcat(new1, new2, combined);
		hconcat(padded, padded2, combined);
		imshow("combined", combined);
		if (waitKey(30) >= 0)
			break;	*/
	////////////////////////////////////////////////////////END OF THE COMBINATION stuff
	int c = 0;
	while (true) {

		Mat zedCam;
		stream1.read(zedCam);
		Rect croppedRect = Rect(0, 0, zedCam.cols / 2, zedCam.rows);
		zedCam = zedCam(croppedRect);
		findTennisBall(zedCam);

		Mat webCam;
		stream2.read(webCam);
		findTennisBall(webCam);

		if ((c / 25) % 2 == 0) {
			imshow("Cam", zedCam);
			++c;
			if (waitKey(30) >= 0) {
				break;
			}
		}
		else {
			imshow("Cam", webCam);
			++c;
			if (waitKey(30) >= 0) {
				break;
			}
		}

	}
	return 0;
}
