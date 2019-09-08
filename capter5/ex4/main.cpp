#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::Mat(cv::Size(210, 210), CV_8UC1, cv::Scalar(0));
    cv::String window = cv::String("window");
    cv::namedWindow(window, cv::WINDOW_AUTOSIZE);
    cv::imshow(window, img);
    cv::waitKey(0);
    cv::Mat img_roi;
    for(int i = 210; i > 0; i -= 10)
    {
        cv::Rect ROI = cv::Rect(0, 0, i, i);
        img_roi = img(ROI);
        img_roi.setTo(cv::Scalar(i));
    }
    cv::imshow(window, img);
    cv::waitKey(0);
    cv::destroyWindow(window);
    return 0;
}



