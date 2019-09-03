#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::imread("arnold_schwarzenegger.jpg", cv::IMREAD_GRAYSCALE);
    if(img.empty())
       return -1;
    cv::namedWindow("arnold_schwarzenegger", cv::WINDOW_AUTOSIZE );
    cv::Mat test = cv::imread("dark.jpg", cv::IMREAD_GRAYSCALE);
    test.copyTo(img(cv::Rect(0, 0, 300, 300)));
    cv::imshow("arnold_schwarzenegger", img);
    cv::waitKey(0);
    return 0;
}



