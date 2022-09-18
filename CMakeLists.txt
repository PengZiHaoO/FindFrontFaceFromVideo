cmake_minimum_required(VERSION 3.16.0)

project( detec_reco )


find_package(OpenCV REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FrameReader)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PersonRecognizer)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FaceDetector)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/CsvWriter)

link_directories(FaceDetector)
link_directories(PersonRecognizer)
link_directories(FrameReade)
link_directories(CsvWriter)

add_subdirectory(FaceDetector)
add_subdirectory(PersonRecognizer)
add_subdirectory(FrameReader)
add_subdirectory(FrameWriter)
add_subdirectory(CsvWriter)

add_executable( ${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${OpenCV_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC FaceDetector
    PUBLIC PersonRecognizer
    PUBLIC FrameReader
    PUBLIC FrameWriter
    PUBLIC CsvWriter
)

find_library(FrameReader NAME FrameReader /build/FrameReader)

target_link_libraries( ${PROJECT_NAME}  
    PUBLIC  ${OpenCV_LIBS}
    PUBLIC  FrameReader
    PUBLIC  FaceDetector
    PUBLIC  PersonRecognizer
    PUBLIC  FrameWriter
    PUBLIC  CsvWriter
)