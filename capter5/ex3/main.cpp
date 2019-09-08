#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::Mat(cv::Size(100, 100), CV_8UC3, cv::Scalar(0, 0, 0));
    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::imshow("image", img);
    cv::waitKey(0);
    for(int i = 20; i <= 40; i++)
        for(int j = 5; j <= 20; j++)
            img.at<cv::Vec3b>(cv::Point(i, j)) = cv::Vec3b(0 ,255, 0);
    cv::imshow("image", img);
    cv::waitKey(0);
    return 0;
}



