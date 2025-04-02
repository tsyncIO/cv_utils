// src/preprocess.cpp
#include "preprocess.hpp"

namespace cv_utils {
    cv::Mat resizeImage(const cv::Mat& image, int width, int height) {
        cv::Mat resized;
        cv::resize(image, resized, cv::Size(width, height));
        return resized;
    }

    cv::Mat applyGaussianBlur(const cv::Mat& image, int kernelSize) {
        cv::Mat blurred;
        cv::GaussianBlur(image, blurred, cv::Size(kernelSize, kernelSize), 0);
        return blurred;
    }
}
