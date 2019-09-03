#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>


cv::Mat numb[10];

void load_img();

int main(int argc, char *argv[])
{
    cv::Mat img = cv::Mat::zeros(cv::Size(500, 500), cv::DEPTH_MASK_8U);
    load_img();
    numb[1].copyTo(img(cv::Rect(0, 0, 10, 20)));
    cv::namedWindow("numbers", cv::WINDOW_AUTOSIZE);
    cv::imshow("numbers", img);
    std::string str;
    char dat;
    for(;;)
    {
        int key = (int)dat;
        if(key != -1)
        {
            if(key >= 48 && key <= 57)
            {
                if(str.size() == 50) break;
                str += dat;
                cv::Mat cp_img = img.clone();
                for(int i = 0; i < str.size(); i++)
                {
                    std::cout<<(int)str[i]<<" "<<i*10<<std::endl;
                    numb[(int)str[i] - 48].copyTo(cp_img(cv::Rect(i*10, 0, numb[i].cols, numb[i].rows)));
                }
                std::cout<<"showed"<<std::endl;
                cv::imshow("numbers", cp_img);
            }
         else if(key == 8)
            {

            }
        }
        dat = cv::waitKey(10);
    }
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

void load_img()
{
    for(int i = 0; i <= 9; i++)
    {
        std::string str = "/home/daniil/ExOpenCv/capter3/3.1/numbers/numb";
        std::stringstream ss;
        ss << i;
        str.append(ss.str()) ;
        str.append(".jpg");
        numb[i] = cv::imread(str);
        cv::resize(numb[i], numb[i], cv::Size(10, 20));
        cv::cvtColor(numb[i], numb[i], cv::COLOR_BGRA2GRAY);
    }
    int arr[5] = {1, 4, 6, 8, 9};
    for(int i = 0; i<= 4; i++) cv::bitwise_not(numb[ arr[i] ], numb[ arr[i] ]);

}

