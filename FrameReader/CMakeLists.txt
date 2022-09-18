project(FrameReader)


include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(../FrameReader)

add_library(${PROJECT_NAME}
    FrameReader.h
    FrameReader.cpp
)

target_link_libraries( ${PROJECT_NAME}  
    PUBLIC  ${OpenCV_LIBS}
)
