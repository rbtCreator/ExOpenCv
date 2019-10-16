#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::imread("/home/daniil/ExOpenCv/capter6/ex1/arnold_schwarzenegger.jpg", CV_LOAD_IMAGE_COLOR);
    if(img.empty())
       return -1;
    cv::namedWindow("arnold_schwarzenegger", CV_WINDOW_AUTOSIZE );
    cv::imshow("arnold_schwarzenegger", img);
    cv::waitKey(0);
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(gray, gray, cv::COLOR_GRAY2BGR);
    cv::putText(gray, cv::String("oolololol"), cv::Point2d(200, 200), cv::FONT_HERSHEY_COMPLEX, 4, cv::Scalar(0, 0, 255), 4);
    cv::imshow("arnold_schwarzenegger", gray);
    std::cout<<gray.channels()<<std::endl;
    cv::waitKey(0);
    return 0;
}



