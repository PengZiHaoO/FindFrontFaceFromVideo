#pragma once

#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class FrameWriter
{
public:
    FrameWriter(const std::string &videoPath, double fps, cv::Size size, int fourcc);
    virtual ~FrameWriter();
    void write(cv::Mat &frame);

private:
    cv::VideoWriter     _video;
    cv::Size            _frame_size;
};

