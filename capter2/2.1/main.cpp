#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>


void info()
{
    std::cout<<"started\n"
    <<"cv version:"<<CV_VERSION
    <<std::endl;
}
void help(char** argv)
{
    std::cout << "\n"
    << "A simple OpenCV program that loads and displays an image from disk\n"
    << argv[0] <<" <path/filename>\n"
	<< "For example:\n"
	<< argv[0] << " ../fruits.jpg\n"
	<< std::endl;
}

int main(int argc, char *argv[])
{
    info();
    if(argc > 1)
    {
        help(argv);
        return 0;
    }
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
    {
        std::cout<<"can't open camera"<<std::endl;
        return -1;
    }
    namedWindow("cam frame", cv::WINDOW_AUTOSIZE );
    std::string mainStr = "/home/daniil/ExOpenCv/save/img";
    int counter = 1;
    for(;;)
    {
        cv::Mat frame;
        cap >> frame;
        if(frame.empty())
        {
            break;
        }
        imshow("cam frame", frame);
        char key = (char) cv::waitKey(10);
        if( key == 'q') break;
        if( key == 'd')
        {
            std::string str = mainStr;
            std::stringstream ss;
            ss << counter;
            str.append(ss.str()) ;
            str.append(".jpg");
            counter++;
            cv::imwrite(str, frame);
            std::cout<<"[OK]\n"
            <<"written "
            <<str<<std::endl;
        }
    }
    return 0;
}



