cmake_minimum_required(VERSION 3.16.0)

project( detec_reco )

find_package(OpenCV REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FrameReader)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PersonRecognizer)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FaceDetector)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/CsvWriter)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cascades)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/obama_faces)

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

target_link_libraries( ${PROJECT_NAME}  
    ${OpenCV_LIBS}
    FrameReader
    FaceDetector
    PersonRecognizer
    FrameWriter
    CsvWriter
)