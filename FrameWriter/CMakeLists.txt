project(FrameWriter)

include_directories(${OpenCV_INCLUDE_DIRS})

add_library(${PROJECT_NAME}
    SHARED
    FrameWriter.h
    FrameWriter.cpp
)
