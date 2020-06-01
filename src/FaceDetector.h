#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <opencv2/opencv.hpp>

#include "Image.h"

extern const std::string FACE_DETECTOR_MODEL_PATH;

/**
 * FaceDetector class does the face detection using cascade face detection classifier
 * Also this class prints the bounding box and prediction text to the image frame
 */
class FaceDetector {

public:
    // Constructor loads the cascade face detection classifier
    FaceDetector();

    // Destructor
    ~FaceDetector() {};

    // Function that runs face detection and draws the bounding box
    Image detectFaceAndDrawRoi( cv::Mat& frame);

    // Function that print the predicted label to the image frame
    Image printPredictionTexttoFrame( Image& image_and_ROI, std::string& emotion_prediction);

private:
    // Face detection classifier
    cv::CascadeClassifier cascade;

    // Output of the face detection classifier
    std::vector<cv::Rect> faces;
    
};

#endif