#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "FaceDetector/FaceDetector.h"
#include "PersonRecognizer/PersonRecognizer.h"
#include "FrameReader/FrameReader.h"
#include "FrameWriter/FrameWriter.h"
#include "CsvWriter/CsvWriter.h"

#define SHOW_OUTPUT
#define WRITE_OUTPUT
#define WRITE_CSV

/** Inputs: **/
#define CASCADE_PATH  "/root/projects/image_processing/face_detect_reco/cascades/haarcascade_frontalface_default.xml"
#define IN_VID        "/root/projects/image_processing/face_detect_reco/input_vid/1.mp4"
#define TRAINING_LIST "/root/projects/image_processing/face_detect_reco/obama_faces/list.txt"

/** Input video: **/
#define START_FRAME  2400
#define END_FRAME    4800
#define FRAMES_DELTA -1

/** Outputs: **/
#define OUT_VID  "1.avi"
#define CSV_FILE "1.csv"

/** Output video: **/
#define OUT_FPS           15
#define OUT_FOURCC        cv::CAP_OPENCV_MJPEG //codec

/** Colors, fonts, lines... **/
#define NO_MATCH_COLOR    cv::Scalar(0,0,255) //red
#define MATCH_COLOR       cv::Scalar(0,255,0) //green
#define FACE_RADIUS_RATIO 0.75
#define CIRCLE_THICKNESS  2.5
#define LINE_TYPE         cv::LINE_AA
#define FONT              cv::FONT_HERSHEY_PLAIN
#define FONT_COLOR        cv::Scalar(255,255,255)
#define THICKNESS_TITLE   1.9
#define SCALE_TITLE       1.9
#define POS_TITLE         cv::Point(10, 30)
#define THICKNESS_LINK    1.6
#define SCALE_LINK        1.3
#define POS_LINK          cv::Point(10, 55)

/** Face detector: **/
#define DET_SCALE_FACTOR   1.01
#define DET_MIN_NEIGHBORS  40
#define DET_MIN_SIZE_RATIO 0.06
#define DET_MAX_SIZE_RATIO 0.18

/** LBPH face recognizer: **/
#define LBPH_RADIUS        3
#define LBPH_NEIGHBORS     8
#define LBPH_GRID_X        8
#define LBPH_GRID_Y        8
#define LBPH_THRESHOLD     180.0


void read_training_set(const std::string &list_path, std::vector<cv::Mat> &images) {
    std::ifstream file(list_path.c_str());;
    std::string path;
    while(std::getline(file, path))
    {
        //std::cout <<  path << '\n';
        images.push_back(cv::imread(path, cv::IMREAD_GRAYSCALE));
    }
}

int main(int argc, char** argv )
{
    FrameReader             frame_reader(std::string(IN_VID), START_FRAME, END_FRAME, FRAMES_DELTA);
    
    cv::Size                frame_size(frame_reader.getSize());
    
    FaceDetector            face_detector(std::string(CASCADE_PATH), DET_SCALE_FACTOR, DET_MIN_NEIGHBORS, 
                                          DET_MIN_SIZE_RATIO, DET_MAX_SIZE_RATIO);

    std::vector<cv::Mat>    training_set;
    
    FrameWriter             frame_writer(std::string(OUT_VID), OUT_FPS, frame_size, OUT_FOURCC);

    CsvWriter               csv_writer(std::string(CSV_FILE));

    read_training_set(std::string(TRAINING_LIST), training_set);
    
    PersonRecognizer        person_recongnizer(training_set, LBPH_RADIUS, LBPH_NEIGHBORS, 
                                               LBPH_GRID_X, LBPH_GRID_Y, LBPH_THRESHOLD);


    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::imshow("Display Image", training_set[0]);
    
    cv::Mat                 mat;
    int                     frame_count = START_FRAME == -1 ? 0 : START_FRAME - 1;
    std::vector<cv::Rect>   faces;

    while (frame_reader.getNextFrame(mat))
    {
        ++frame_count;
        std::printf("10 ");
        csv_writer.addEntry(cv::format("%d", frame_count));

        face_detector.FindFacesInImage(mat, faces);

        bool    has_match        =  false;
        double  match_confidence =  0.0;

        for(auto &face : faces)
        {
            cv::Scalar  color       =   NO_MATCH_COLOR;
            cv::Mat     face_img    =   mat(face);

            bool        face_match  =   false;
            double      confidence  =   0.0;

            if(person_recongnizer.recognize(face_img, confidence))
            {
                color               =   MATCH_COLOR;
                has_match           =   true;
                face_match          =   true;
                match_confidence    =   confidence;    
            }

            cv::Point   center(face.x + face.width * 0.5, face.y + face.height * 0.5);
            cv::circle(mat, center, FACE_RADIUS_RATIO, color, CIRCLE_THICKNESS, LINE_TYPE);

            csv_writer.addEntry(cv::format("%f", face_match ? confidence : 0));
        }

        csv_writer.nextLine();

        cv::putText(mat, "Face recognition demo (frontal)", POS_TITLE,
                FONT, SCALE_TITLE, FONT_COLOR, THICKNESS_TITLE, LINE_TYPE);
        cv::putText(mat, cv::format("Frame: %d", frame_count), cv::Point(10, mat.rows - 105),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        cv::putText(mat, cv::format("FPS: %d", 15), cv::Point(10, mat.rows - 80),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        cv::putText(mat, cv::format("Faces: %ld", faces.size()), cv::Point(10, mat.rows - 55),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        cv::putText(mat, cv::format("Match: %s", has_match ? "True" : "False"), cv::Point(10, mat.rows - 30),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);
        cv::putText(mat, cv::format("Confidence: %f", has_match ? match_confidence : 0), cv::Point(10, mat.rows - 5),
                FONT, 2, FONT_COLOR, 1, LINE_TYPE);

        cv::imshow("OutPut", mat);

        if('x' == cv::waitKey(0))
        {
            std::printf("Bye!");

            return 0;
        }

        frame_writer.write(mat);
    }
                              

    return 0;
}