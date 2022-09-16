#include <cstdio>
#include <opencv2/opencv.hpp>


#include "FaceDetector/FaceDetector.h"

using namespace cv;
int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        std::printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    const Mat image = imread( argv[1], 1 );
    if ( !image.data )
    {
        std::printf("No image data \n");
        return -1;
    }
    

    return 0;
}