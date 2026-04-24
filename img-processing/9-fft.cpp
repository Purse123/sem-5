#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <complex>

#define IMG_FILE "grayscale.png"

// IF YOU REALLLY REALLL WANT TO LEARN THIS FFT
// [WATCH]: https://www.youtube.com/watch?v=c9_Az6ys7cU
void cooley_tukey_fft(std::vector<std::complex<float>> &pixels);

int main() {
  // #############################################
  //              OpenCV stuffs
  // #############################################
  cv::Mat img = cv::imread(IMG_FILE, cv::IMREAD_COLOR_BGR);
  if (img.empty()) {
    std::cerr << "Failed to load image" << std::endl;
    return -1;
  }
  
  // #############################################
  //               My Blobs
  // #############################################
  int rows = img.rows;
  int cols = img.cols;
  int channels = img.channels();
  int total_pixels = rows * cols;
  
  std::vector<int> pixel_matrix;
  pixel_matrix.reserve(total_pixels * channels);

  // raw img pixel [0, 255]
  uchar* data = img.data;
  for (int i = 0; i < total_pixels; i++) {
    uchar value = data[i];
      
    int temp = std::max(0, std::min(255, static_cast<int>(value)));
    pixel_matrix.push_back(temp);
  }
  
  // [CONVERSION] int -> complex
  std::vector<float> float_pixel(total_pixels);
  std::vector<std::complex<float>> complex_pixel(total_pixels);
  
  for (int i = 0; i < total_pixels; i++) {
    float_pixel[i] = static_cast<float>(pixel_matrix[i]);
    complex_pixel[i] = std::complex<float>(float_pixel[i], 0.0f);
  }


  // #############################################
  //                FFT Experiments
  // #############################################
  cooley_tukey_fft(complex_pixel);

  // #############################################
  //                TESTING
  // #############################################
  // [TEST] Display img pixel
  for (int i = 0; i < total_pixels; i++) {
    std::cout << complex_pixel[i] << "\t";
  }
  std::cout << "\n";
  
  return 0;
}

void cooley_tukey_fft(std::vector<std::complex<float>> &pixels) {
  size_t len = pixels.size();

  // [TSET] std::cout << "point: " << len << std::endl;
  if (len <= 1) {
    return;
  }

  // spliting odd even indices
  std::vector<std::complex<float>> even(len/2), odd(len/2);
  for (int i = 0; i < len/2; ++i) {
    even[i] = pixels[2 * i];
    odd[i]  = pixels[2 * i + 1];
  }
  
  // even scheiße <= left halves
  cooley_tukey_fft(even);
  // odd scheiße
  cooley_tukey_fft(odd);

  // twiddle factor/rotate complex number why?
  // encode position info so can transform 2nF image-space and frequency-space
  // without: can't go back to original image
  for (int i = 0; i < len/2; ++i) {
    // W^i = e^(-2πi × i / n) = cos(2πi/n) +- i·sin(2πi/n)
    float angle = -2.0f * M_PI * i / len;
    std::complex<float> twiddle(cos(angle), sin(angle));

    // X[i] = E[i] + W^k × Odd[i]
    // X[i + len/2] = E[i] - W^k × Odd[i]
    std::complex<float> t = twiddle * odd[i];
    pixels[i] = even[i] + t;
    pixels[i + len/2] = even[i] - t;
  }
}
