#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    cv::Mat img = cv::imread("arnold_schwarzenegger.jpg", CV_LOAD_IMAGE_COLOR);
    if(img.empty())
       return -1;
    cv::String window = cv::String("window");
    cv::namedWindow(window, CV_WINDOW_AUTOSIZE );
    cv::imshow(window, img);
    cv::waitKey(0);
    //std::cout<<img.size()<<std::endl;
    cv::Mat gray;
    cv::cvtColor(img, gray, CV_BGR2GRAY);
    cv::imshow(window, gray);
    cv::waitKey(0);
    cv::Rect ROI_1 = cv::Rect(0, 0, 100, 100);
    cv::Rect ROI_2 = cv::Rect(180, 180, 400, 400);
    cv::Mat gray_roi_1 = gray(ROI_1);
    cv::Mat gray_roi_2 = gray(ROI_2);
    cv::bitwise_not(gray_roi_1, gray_roi_1);
    cv::bitwise_not(gray_roi_2, gray_roi_2);
    cv::imshow(window, gray);
    cv::waitKey(0);
    cv::destroyWindow(window);
    return 0;
}



