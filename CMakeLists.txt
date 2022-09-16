cmake_minimum_required(VERSION 2.8)

project( detec_reco )


find_package( OpenCV REQUIRED )

add_subdirectory(FaceDetector)
include_directories(FaceDetector)

add_executable( ${PROJECT_NAME} main.cpp )

target_include_directories(${PROJECT_NAME}
    PUBLIC ${OpenCV_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} PUBLIC FaceDetector)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} FaceDetector)