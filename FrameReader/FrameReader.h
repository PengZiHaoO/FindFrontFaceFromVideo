#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class FrameReader
{
public:
    FrameReader(std::string videoPath, int startFrame = -1, int endFrame = -1, int delta = -1);
    virtual ~FrameReader();
    bool getNextFrame(cv::Mat &frame);
    cv::Size getSize();

private:
    cv::VideoCapture    _video;
    int                 _endFrame;
    int                 _delta;
    
};


