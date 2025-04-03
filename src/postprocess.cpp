// src/postprocess.cpp
#include "postprocess.hpp"

namespace cv_utils {
    void drawBoundingBoxes(cv::Mat& image, const std::vector<cv::Rect>& boxes) {
        for (const auto& box : boxes) {
            cv::rectangle(image, box, cv::Scalar(0, 255, 0), 2);
        }
    }

    cv::Mat applyMaskToImage(const cv::Mat& image, const cv::Mat& mask) {
        cv::Mat result;
        image.copyTo(result, mask);
        return result;
    }
}
