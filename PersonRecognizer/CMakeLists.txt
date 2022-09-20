project(PersonRecognizer)

include_directories(${OpenCV_INCLUDE_DIRS})

add_library(${PROJECT_NAME}
    SHARED
    PersonRecognizer.h
    PersonRecognizer.cpp
)

target_link_libraries(PersonRecognizer opencv_face)


