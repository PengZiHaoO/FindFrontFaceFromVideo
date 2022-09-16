project(FaceDetector)

include_directories(${OpenCV_INCLUDE_DIRS})

add_library(${PROJECT_NAME}
    SHARED
    FaceDetector.h
    FaceDetector.cpp
)