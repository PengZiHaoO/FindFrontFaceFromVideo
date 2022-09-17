cmake_minimum_required(VERSION 3.16.0)

project( detec_reco )


find_package( OpenCV REQUIRED )

add_subdirectory(FaceDetector)
add_subdirectory(PersonRecognizer)
add_subdirectory(FrameReader)
add_subdirectory(FrameWriter)
add_subdirectory(CsvWriter)

include_directories(FaceDetector)
include_directories(PersonRecognizer)
include_directories(FrameReade)
include_directories(CsvWriter)

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
    FaceDetector
    PersonRecognizer
    FrameReader
    FrameWriter
    CsvWriter
)