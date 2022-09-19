project(FrameReader)


include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(../FrameReader)

add_library(${PROJECT_NAME}
    FrameReader.cpp
)

