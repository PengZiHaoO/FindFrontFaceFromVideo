#include "FrameWriter.h"

FrameWriter::FrameWriter(const std::string &videoPath, 
                         double fps, 
                         cv::Size size, 
                         int fourcc):
                         _frame_size(size)

{
    _video.open(
        videoPath,
        fourcc,
        fps,
        _frame_size,
        true
    );
}

FrameWriter::~FrameWriter()
{
    _video.release();
}

void FrameWriter::write(cv::Mat &frame)
{
    _video << frame;
}