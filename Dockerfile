
# 🖼️ CVUtils - A Modular C++ Library for Object Detection & Segmentation Pre/Post-Processing

**CVUtils** is a modular **C++ library** that provides essential **pre-processing and post-processing** utilities for **2D object detection and segmentation** pipelines. It simplifies inference-time processing, ensuring smooth integration of deep learning models into real-world applications.

## ✨ Features  
✔️ Image Preprocessing: Resizing, normalization, augmentation  
✔️ Postprocessing: NMS, bounding box filtering, mask refinement  
✔️ Optimized for **OpenCV** and **Eigen**  
✔️ Modular and **header-only** design  
✔️ Easy integration with **YOLO, Faster R-CNN, Mask R-CNN** models  
✔️ Supports **batch processing**  

---

## 📦 Installation  

### **1️⃣ Prerequisites**
Ensure you have the following installed:
- **CMake 3.10+** (for building)
- **OpenCV 4+** (for image processing)
- **Eigen** (for matrix operations)

### **2️⃣ Clone & Build**
```bash
git clone https://github.com/yourusername/CVUtils.git
cd CVUtils
mkdir build && cd build
cmake ..
make -j$(nproc)
```

---

## 🚀 Usage  

### **Include in Your Project**
```cpp
#include "cvutils/ImagePreprocessor.h"
#include "cvutils/PostProcessor.h"
```

### **Example: Preprocessing an Image**
```cpp
#include <opencv2/opencv.hpp>
#include "cvutils/ImagePreprocessor.h"

int main() {
    cv::Mat img = cv::imread("image.jpg");
    cv::Mat resized, normalized;
    
    cvutils::ImagePreprocessor preprocessor;
    resized = preprocessor.resize(img, 640, 480);
    normalized = preprocessor.normalize(resized, 0.0, 1.0);
    
    cv::imshow("Processed Image", normalized);
    cv::waitKey(0);
    return 0;
}
```

### **Example: Post-processing Object Detections**
```cpp
#include "cvutils/PostProcessor.h"

std::vector<cv::Rect> boxes = {{50, 50, 100, 100}, {55, 55, 100, 100}};
std::vector<float> scores = {0.9, 0.85};
std::vector<int> indices;

cvutils::PostProcessor postprocessor;
indices = postprocessor.nonMaxSuppression(boxes, scores, 0.5);

for (int idx : indices) {
    std::cout << "Kept Box: " << boxes[idx] << std::endl;
}
```

---

## 📖 API Documentation  

### **1️⃣ Image Preprocessor (`cvutils::ImagePreprocessor`)**
| Function | Description |
|----------|------------|
| `cv::Mat resize(const cv::Mat &image, int width, int height)` | Resize image to specified dimensions. |
| `cv::Mat normalize(const cv::Mat &image, float min, float max)` | Normalize pixel values to a given range. |
| `cv::Mat denoise(const cv::Mat &image, int kernelSize = 3)` | Apply Gaussian blur for noise reduction. |

### **2️⃣ Post Processor (`cvutils::PostProcessor`)**
| Function | Description |
|----------|------------|
| `std::vector<int> nonMaxSuppression(...)` | Apply NMS to filter overlapping bounding boxes. |
| `std::vector<cv::Rect> clipBoxes(...)` | Ensure bounding boxes remain within image boundaries. |

---

## 🔧 Directory Structure  

```bash
CVUtils/
│── include/cvutils/
│   ├── ImagePreprocessor.h
│   ├── PostProcessor.h
│── src/
│   ├── ImagePreprocessor.cpp
│   ├── PostProcessor.cpp
│── examples/
│   ├── preprocess_example.cpp
│   ├── postprocess_example.cpp
│── tests/
│   ├── test_preprocessor.cpp
│   ├── test_postprocessor.cpp
│── CMakeLists.txt
│── README.md
│── LICENSE
```

---

## 🛠️ Contribution  

**Want to improve CVUtils?** Follow these steps:  
1. **Fork the repo**  
2. **Create a new branch** (`git checkout -b feature-newFunctionality`)  
3. **Commit your changes** (`git commit -m "Added new function for ..."`)  
4. **Push to your branch** (`git push origin feature-newFunctionality`)  
5. **Create a Pull Request** 🚀 
6. Help needed for Tensor handling implementation and further modifications
7. Help needed for multi-threading implementation and further modifications

---

## The tensor data structure handling will be added soon

## 📜 License  

**MIT License** - You are free to use, modify, and distribute this library under the terms of the **MIT license**.

---

## 📬 Contact  

For any questions, issues, or collaborations:  
📧 **mtanvir360@gmail.com**  


---

⭐ **If you find this useful, give the repo a star!** ⭐  
