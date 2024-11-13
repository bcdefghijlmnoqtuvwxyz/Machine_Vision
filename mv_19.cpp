#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// saturate_cast() 함수는 포화 연산을 수행하는 함수이다.
// 포화 연산을 수행하지 않으면 0~255의 값을 갖는 그레이스케일에서 
// 255를 초과한 값이 들어오면 0으로 초기화되어 그 값에서 더해지므로 
// 값이 클수록 밝아져야 되지만 반대로 어두워짐

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst(src.rows, src.cols, src.type());

    for(int j = 0; j < src.rows; j++) {
        for(int i = 0; i < src.cols; i++) {
            dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
        }
    }

    imshow("src", src);
    inshow("dst", dst);

    waitKey();
    destroyAllWindows();

    return 0;
}