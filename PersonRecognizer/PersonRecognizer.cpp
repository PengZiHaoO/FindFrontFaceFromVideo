#include "PersonRecognizer.h"

PersonRecognizer::PersonRecognizer(const std::vector<cv::Mat> &imgs, 
                                   int radius, 
                                   int neighbors,
                                   int grid_x, int grid_y, 
                                   double threshold)
{
    std::vector<int> labels(imgs.size());
    for(auto &label : labels)
    {
        label = PERSON_LABEL;
    }

    _faceSize = cv::Size(imgs[0].size().width, imgs[0].size().height);

    _model = cv::face::LBPHFaceRecognizer::create(radius, neighbors, grid_x, grid_y, threshold);
    _model->train(imgs, labels);
}

PersonRecognizer::~PersonRecognizer()
{

}

bool PersonRecognizer::recognize(const cv::Mat &face, double &confidence) const 
{
    cv::Mat gray;

    int label;

    cv::cvtColor(face, gray, cv::COLOR_BGR2GRAY);
    cv::resize(gray, gray, _faceSize);

    _model->predict(gray, label, confidence);

    return label == PERSON_LABEL ? true : false;
}