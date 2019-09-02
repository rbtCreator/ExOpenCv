#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>


int increase        = 1;
int slider_position = 0;


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

void onSlider( int pos, void *)
{
    increase = pos;
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
    cv::namedWindow("cam frame", cv::WINDOW_AUTOSIZE );
    cv::namedWindow("increase", cv::WINDOW_NORMAL);
    cv::createTrackbar("Subpix", "increase", &slider_position, 4, onSlider);
    std::cout<<increase<<std::endl;
    for(;;)
    {
        cv::Mat frame, inc_frame;
        cap >> frame;
        if(frame.empty())
        {
            break;
        }
        imshow("cam frame", frame);
        cv::cvtColor(frame, inc_frame, cv::COLOR_BGR2GRAY);
        for(int i = 0; i<increase; i++)
        {
            cv::pyrDown(inc_frame, inc_frame);
        }
        cv::imshow("increase", inc_frame);
        char key = (char) cv::waitKey(10);
        if( key == 'q') break;
        if( key == 'd') std::cout<<inc_frame.size()<<std::endl;
    }
    return 0;
}


