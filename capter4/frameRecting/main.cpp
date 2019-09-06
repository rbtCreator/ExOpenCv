#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

void random_colour(cv::Mat &);
void fill_img(cv::Mat &, cv::Mat &);

int main(int argc, char *argv[])
{
    cv::Mat randImg = cv::Mat(100, 200, cv::DEPTH_MASK_8U);
    cv::namedWindow("window", cv::WINDOW_NORMAL);
    random_colour(randImg);
    cv::Mat intImg = cv::Mat1f(100, 200, cv::DEPTH_MASK_64F);
    intImg.at<float>(cv::Point(50,50)) = 2.0;
    float* p = intImg.ptr<float>(50, 50);
    std::cout<<*p<<std::endl;
    std::cout<<"Start filling integrate image"<<std::endl;
    fill_img(randImg, intImg);
    std::cout<<"status: [OK]"<<std::endl;
    cv::imshow("window", randImg);
    cv::waitKey(0);
    cv::destroyWindow("window");
    return 0;
}

void fill_img(cv::Mat & input, cv::Mat & output)
{
    cv::Mat img;
    input.convertTo(img, cv::DEPTH_MASK_64F);
    std::cout<<img.type()<<std::endl;
    for(int x = 0; x < input.cols; x++)
        for(int y = 0; y < input.rows; y++)
            for(int i = 0; i <= x; i++)
                for(int j = 0; j <= y; j++)
                {
                    float* xy = output.ptr<float>(x, y);
                    float* ij = img.ptr<float>(i, j);
                    //std::cout<<*ij<<std::endl;
                    //std::cout<<*xy + *ij<<std::endl;
                    output.at<float>(cv::Point(x, y)) = *ij;

                }

}

void random_colour(cv::Mat &image)
{
    for(int i = 0; i < image.rows; i++)
        for(int j = 0; j < image.cols; j++)
            image.at<uchar>(i,j) = rand()%255;
}



