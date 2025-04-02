// include/preprocess.hpp
#ifndef PREPROCESS_HPP
#define PREPROCESS_HPP

#include <opencv2/opencv.hpp>

namespace cv_utils {
    cv::Mat resizeImage(const cv::Mat& image, int width, int height);
    cv::Mat applyGaussianBlur(const cv::Mat& image, int kernelSize);
}

#endif
