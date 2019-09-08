#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::Mat(cv::Size(100, 100), CV_8UC3, cv::Scalar(0, 0, 0));
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    cv::imshow("image", img);
    cv::waitKey(0);
    cv::rectangle(img, cv::Point(20,5), cv::Point(40,20), cv::Scalar(0, 255, 0), -1);
    cv::imshow("image", img);
    cv::waitKey(0);
    return 0;
}



