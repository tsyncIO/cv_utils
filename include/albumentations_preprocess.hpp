#ifndef ALBUMENTATIONS_PREPROCESS_HPP
#define ALBUMENTATIONS_PREPROCESS_HPP

#include <opencv2/opencv.hpp>

namespace cv_utils {

    // Random crop from the given image
    cv::Mat applyRandomCrop(const cv::Mat& image, int height, int width);

    // Adjust brightness and contrast
    cv::Mat applyRandomBrightnessContrast(const cv::Mat& image, float brightness_limit = 0.2f, float contrast_limit = 0.2f);

    // Apply random horizontal flip
    cv::Mat applyHorizontalFlip(const cv::Mat& image, float flip_prob = 0.5f);
    
}

#endif // ALBUMENTATIONS_PREPROCESS_HPP
