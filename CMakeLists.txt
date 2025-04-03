cmake_minimum_required(VERSION 3.10)
project(cv_utils)

find_package(OpenCV REQUIRED)

add_library(cv_utils STATIC
    src/preprocess.cpp
    src/postprocess.cpp
)

target_include_directories(cv_utils PUBLIC include)
target_link_libraries(cv_utils PUBLIC ${OpenCV_LIBS})
