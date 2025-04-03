#include "cv_utils.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load an example image
    cv::Mat image = cv::imread("example_image.jpg");
    if (image.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    }

    // Apply random crop
    cv::Mat cropped = cv_utils::applyRandomCrop(image, 100, 100);
    cv::imshow("Cropped", cropped);

    // Apply random brightness and contrast
    cv::Mat bright_contrast = cv_utils::applyRandomBrightnessContrast(image);
    cv::imshow("Brightness & Contrast Adjusted", bright_contrast);

    // Apply horizontal flip
    cv::Mat flipped = cv_utils::applyHorizontalFlip(image);
    cv::imshow("Flipped", flipped);

    // Wait for key press
    cv::waitKey(0);

    return 0;
}
