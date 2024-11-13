#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

void on_brightness(int pos, void* userdata);

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    namedWindow("dst");
    createTrackbar("Briightness", "dst", 0, 100, on_brightness, (void*)&src);
    // dst 창에 트랙바를 부착

    on_brightness(0, (void*)&src);

    waitKey();
    destroyAllWindows();

    return 0;
}

void on_brightness(int pos, void* userdata)
{
    Mat src = *(Mat*)userdata;
    Mat dst = src + pos;

    imshow("dst", dst);
}