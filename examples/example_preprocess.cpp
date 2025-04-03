// examples/example_preprocess.cpp
#include <opencv2/opencv.hpp>
#include "cv_utils.hpp"

int main() {
    cv::Mat image = cv::imread("example.jpg");
    if (image.empty()) return -1;

    cv::Mat resized = cv_utils::resizeImage(image, 300, 300);
    cv::Mat blurred = cv_utils::applyGaussianBlur(resized, 5);

    cv::imshow("Resized", resized);
    cv::imshow("Blurred", blurred);
    cv::waitKey(0);
    return 0;
}
