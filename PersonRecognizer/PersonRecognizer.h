#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/face.hpp>
#include <vector>

#include "FaceDetector.h"

class PersonRecognizer
{
public:
    PersonRecognizer(const std::vector<cv::Mat> &imgs, 
                     int radius, 
                     int neighbors,
                     int grid_x, int grid_y, 
                     double threshold);
    virtual ~PersonRecognizer();

    bool recognize(const cv::Mat &face, double &confidence) const;

private:
    cv::Ptr<cv::face::FaceRecognizer>  _model;
    cv::Size                           _faceSize;
    
};

