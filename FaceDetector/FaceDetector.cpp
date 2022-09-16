#include "FaceDetector.h"

FaceDetector::FaceDetector(const std::string &cascadePath, 
                 double scaleFactor,
                 int minNeighbors,
                 double minSizeRatio,
                 double maxSizeRatio
                ):
                _cascade(cascadePath),
                _scaleFactor(scaleFactor),
                _minNeighbors(minNeighbors),
                _minSizeRatio(minSizeRatio),
                _maxSizeRatio(maxSizeRatio)
{
    _cascade.load(cascadePath);
}

FaceDetector::~FaceDetector()
{

}

void FaceDetector::FindFacesInImage(const cv::Mat &img, std::vector<cv::Rect> &res)
{
    cv::Mat temp;

    int width  = img.size().width;
    int height = img.size().height; 

    cv::Size minScaleSize = cv::Size(_minSizeRatio  * width, _minSizeRatio  * height);
    cv::Size maxScaleSize = cv::Size(_maxSizeRatio  * width, _maxSizeRatio  * height);

    cv::cvtColor(img, temp, cv::COLOR_BGR2GRAY);

    cv::equalizeHist(temp, temp);

    _cascade.detectMultiScale(img, res, _scaleFactor, _minNeighbors, 0, minScaleSize, maxScaleSize);
}