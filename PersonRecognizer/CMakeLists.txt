project(PersonRecognizer)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(../PersonRecognizer)

add_library(${PROJECT_NAME}
    SHARED
    PersonRecognizer.h
    PersonRecognizer.cpp
)

