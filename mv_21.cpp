#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 명암비를 효과적으로 높이기 위해서는 밝은 픽셀은 더 밝게, 어두운 픽셀은 더 어둡게 변경해야 함
// 그레이스케일의 중간값인 128을 기준으로 설정할 수 있고, 입력 영상의 평균 밝기를 구하여 기준으로 삼을 수 있음
// 픽셀값이 128보다 크면 더욱 밝게, 128보다 작으면 더욱 어둡게 만드는 방식

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    float alpha = 1.f;
    Mat dst = src + (src - 128) * alpha;

    imshow("src", src);
    imshow("dst", dst);

    waitkey();
    destroyAllWindows();

    return 0;
}