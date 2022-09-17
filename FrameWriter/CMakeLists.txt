project(FrameWriter)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(../FrameWriter)

add_library(${PROJECT_NAME}
    SHARED
    FrameWriter.h
    FrameWriter.cpp
)
