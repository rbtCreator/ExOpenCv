#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::Mat(cv::Size(500, 500), cv::DEPTH_MASK_8U, cv::Scalar(0));
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    cv::imshow("image", img);
    cv::waitKey(0);
    cv::circle(img, cv::Point(250,250), 50, cv::Scalar(125), -1);
    cv::imshow("image", img);
    cv::waitKey(0);
    return 0;
}



