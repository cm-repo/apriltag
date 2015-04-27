#ifndef APRILTAGS_FLOATIMAGE_H_
#define APRILTAGS_FLOATIMAGE_H_

#include <algorithm>
#include <vector>
#include <opencv2/core/core.hpp>

namespace DualCoding {
typedef unsigned char uchar;
template <typename T>
class Sketch;
}

namespace AprilTags {

//! Represent an image as a vector of floats in [0,1]
class FloatImage {
 private:
  int width;
  int height;
  std::vector<float> pixels;

 public:
  //! Default constructor
  FloatImage() = default;
  FloatImage(const cv::Mat& image);

  //! Construct an empty image
  FloatImage(int widthArg, int heightArg);

  FloatImage& operator=(const FloatImage& other);

  float get(int x, int y) const { return image_.at<float>(y, x); }
  void set(int x, int y, float v) { image_.at<float>(y, x) = v; }

  int getWidth() const { return image_.cols; }
  int getHeight() const { return image_.rows; }
  int getNumFloatImagePixels() const { return image_.cols * image_.rows; }

  void filterFactoredCentered(int ksize, float sigma);

  cv::Mat image_;
};

}  // namespace AprilTags

#endif  // APRILTAGS_FLOATIMAGE_H_
