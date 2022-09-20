project(FrameReader)


include_directories(${OpenCV_INCLUDE_DIRS})

add_library(${PROJECT_NAME}
    FrameReader.cpp
)

