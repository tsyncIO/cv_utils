// tests/test_preprocess.cpp
#include <opencv2/opencv.hpp>
#include "cv_utils.hpp"
#include <cassert>

int main() {
    cv::Mat dummy = cv::Mat::zeros(100, 100, CV_8UC3);
    cv::Mat resized = cv_utils::resizeImage(dummy, 50, 50);
    assert(resized.rows == 50 && resized.cols == 50);
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}
