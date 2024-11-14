#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 미디언 필터(median filter)는 입력 영상에서 자기 자신 픽셀과 주변 픽셀 값 중에서 
// 중간값을 선택하여 결과 영상 픽셀 값으로 설정하는 필터링 기법
// 잡음 픽셀 값이 주변 픽셀 값과 큰 차이가 있는 경우에 효과적으로 동작
// 잡음 중 소금 & 후추 잡음(salt & pepper noise)은 픽셀 값이 일정 확률로 0 또는 255로 변경되는 형태의 잡음
// 이런 잡음에 미디언 필터를 적용하면 원본 영상의 픽셀 값이 중간값으로 적용되기 때문에 잡음은 효과적으로 제거됨

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    int num = (int)(src.total() * 0.1);

    for(int i = 0; i < num; i++) { // 10%에 해당하는 픽셀 값을 0 또는 255로 설정
        int x = rand() % src.cols;
        int y = rand() % src.rows;
        src.at<uchar>(y, x) = (i % 2) * 255;
    }

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 1); // 표준 편차 1인 가우시안 필터링

    Mat dst2;
    medianBlur(src, dst2, 3); // 크기가 3인 미디언 필터를 실행

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();

    return 0;
}