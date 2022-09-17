#pragma once 

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

const int PERSON_LABEL = 10;

class FaceDetector{
public:
    FaceDetector(const std::string &cascadePath, 
                 double scaleFactor,
                 int minNeighbors,
                 double minSizeRatio,
                 double maxSizeRatio
                );
    virtual ~FaceDetector();

    void FindFacesInImage(const cv::Mat &img, std::vector<cv::Rect> &res);

private:
    cv::CascadeClassifier _cascade;
    double                _scaleFactor;
    int                   _minNeighbors;
    double                _minSizeRatio;
    double                _maxSizeRatio;

};

