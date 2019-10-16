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
    cv::vector<cv::Mat> ch;
    cv::split(img, ch);
    cv::Mat clone = ch[1];
    cv::Mat clone1 = clone.clone(), clone2 = clone.clone();
    cv::mi
    cv::imshow(window, clone1);
    cv::waitKey(0);
    cv::destroyWindow(window);
    return 0;
}

