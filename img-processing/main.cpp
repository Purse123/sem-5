#include <opencv2/opencv.hpp>
#include <iostream>

#define IMG_FILE "doom.png"

int main() {
  // #############################################
  //              OpenCV stuffs
  // #############################################
  /**
     @brief Loads an image from a file.
     @anchor imread
     returns OpenCV matrix.
     If cannot be read the function returns an empty matrix.
     @param filename Name of the file to be loaded.
     @param flags Flag that can take values cv::ImreadModes, default cv::IMREAD_COLOR_BGR.
  */
  cv::Mat img = cv::imread(IMG_FILE, cv::IMREAD_COLOR_BGR);
  if (img.empty()) {
    std::cerr << "Failed to load image" << std::endl;
    return -1;
  }
  
  // #############################################
  //         My Blobs, Experiments
  // #############################################
  int rows = img.rows;
  int cols = img.cols;
  int channels = img.channels();
  int total_pixels = rows * cols;
  
  std::vector<int> pixel_matrix;
  pixel_matrix.reserve(total_pixels * channels);
  
  // Trying to access pixel as raw array
  uchar* data = img.data;
  for (int i = 0; i < total_pixels * 3; i++) {
    uchar value = data[i];
      
    int temp = std::max(0, std::min(255, static_cast<int>(value)));
    pixel_matrix.push_back(temp);
  }

  std::cout << "First pixel: " << std::endl
	    << "B: " << pixel_matrix[0]
	    << "B: " << pixel_matrix[1]
	    << "B: " << pixel_matrix[2] << std::endl;

  // Now pixel_matrix is made now making it Gray scale, channel = 1
  std::vector<int> gray_matrix(total_pixels);
  
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int idx = (r * cols + c) * 3;

      uchar B = pixel_matrix[idx + 0];
      uchar G = pixel_matrix[idx + 1];
      uchar R = pixel_matrix[idx + 2];

      // int intensity = (0.114f * B + 0.587f * G + 0.299f * R);
      int intensity = (0.5f * B + 0.5f * G + 0.5f * R);
      
      gray_matrix[r * cols + c] = intensity;
    }
  }

  // convert gray_matrix from int to Mat to display
  std::vector<uchar> gray_uchar(total_pixels);
  for (int i = 0; i < total_pixels; i++) {
    gray_uchar[i] = static_cast<uchar>(gray_matrix[i]);
  }
  
  cv::Mat gray_img(rows, cols, CV_8UC1, gray_uchar.data());
  
  // #############################################
  //                    GUI
  // #############################################
  // cv::imshow("mehh", img);
  cv::imshow("mehh", gray_img);

  // save image 
  cv::imwrite("grayscale_output.png", gray_img);
  
  // #############################################
  //               Event Handler
  // #############################################
  while (true) {
    int key = cv::waitKey(0);
    if (key == 27) break;
  }

  // #############################################
  //           Destroy window & pointers
  // #############################################
  cv::destroyAllWindows();
  return 0;
}
