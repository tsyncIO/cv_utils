// include/postprocess.hpp
#ifndef POSTPROCESS_HPP
#define POSTPROCESS_HPP

#include <opencv2/opencv.hpp>

namespace cv_utils {
    void drawBoundingBoxes(cv::Mat& image, const std::vector<cv::Rect>& boxes);
    cv::Mat applyMaskToImage(const cv::Mat& image, const cv::Mat& mask);
}

#endif
