project(PersonRecognizer)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(../FaceDetector)

add_library(${PROJECT_NAME}
    SHARED
    PersonRecognizer.h
    PersonRecognizer.cpp
)

#target_include_directories(${PROJECT_NAME} PUBLIC FaceDetector)