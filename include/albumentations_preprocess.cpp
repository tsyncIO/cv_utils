#include "albumentations_preprocess.hpp"
#include <opencv2/opencv.hpp>
#include <random>

namespace cv_utils {

    // Apply random crop
    cv::Mat applyRandomCrop(const cv::Mat& image, int height, int width) {
        // Ensure the crop size is smaller than the image
        if (image.rows <= height || image.cols <= width) {
            std::cerr << "Crop size exceeds image size" << std::endl;
            return image;  // Return the original image if invalid
        }

        int x = rand() % (image.cols - width); // Random x-coordinate for the crop
        int y = rand() % (image.rows - height); // Random y-coordinate for the crop

        cv::Rect roi(x, y, width, height);
        cv::Mat cropped = image(roi);

        return cropped;
    }

    // Apply random brightness and contrast adjustments
    cv::Mat applyRandomBrightnessContrast(const cv::Mat& image, float brightness_limit, float contrast_limit) {
        cv::Mat result = image.clone();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-brightness_limit, brightness_limit);

        // Random brightness adjustment
        float brightness = dis(gen);
        result.convertTo(result, -1, 1, brightness);

        // Random contrast adjustment
        float contrast = dis(gen);
        result.convertTo(result, -1, 1 + contrast, 0);

        return result;
    }

    // Apply random horizontal flip with a certain probability
    cv::Mat applyHorizontalFlip(const cv::Mat& image, float flip_prob) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        if (dis(gen) < flip_prob) {
            cv::Mat flipped;
            cv::flip(image, flipped, 1);  // Flip horizontally
            return flipped;
        }

        return image;  // Return original image if no flip
    }
}
