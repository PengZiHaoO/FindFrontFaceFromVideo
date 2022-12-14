#include "FrameReader.h"

FrameReader::FrameReader(std::string videoPath, 
                         int startFrame/* = -1*/, 
                         int endFrame/* = -1*/, 
                         int delta/* = -1*/):
                         _endFrame(endFrame),
                         _delta(delta)
{
    _video.open(videoPath);

    if(startFrame != -1)
    {
        _video.set(cv::CAP_PROP_POS_FRAMES, startFrame);
    }
}

FrameReader::~FrameReader()
{
    _video.release();
}

cv::Size FrameReader::getSize()
{
    return cv::Size(
        _video.get(cv::CAP_PROP_FRAME_WIDTH),
        _video.get(cv::CAP_PROP_FRAME_HEIGHT)
    );
}

bool FrameReader::getNextFrame(cv::Mat &frame)
{
    if (_delta != -1)
        _video.set(cv::CAP_PROP_POS_FRAMES, _video.get(cv::CAP_PROP_POS_FRAMES) + _delta);
    if (_endFrame != -1 && _video.get(cv::CAP_PROP_POS_FRAMES) > _endFrame)
        return false;
    return _video.read(frame);
}