#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 가우시안 분포는 평균을 중심으로 좌우 대칭의 종 모양을 갖는 확률분포를 의미, 정규 붙포(normal distribution)라고도 함

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(!src.empty()) {
        cerr << "Image load failed" << endl;
        return;
    }
    
    imshow("src", src);

    Mat dst;

    for(int sigma = 1; sigma <= 5; sigma++) {
        GaussianBlur(src, dst, Size(), (double)sigma); 
        // 가우시안 표준 편차를 증가시킴, 표준 편차 값이 커질수록 흐릿해짐

        String text = format("sigma = %d", sigma);
        putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey(0);
    }

    distroyAllWindows();

    return 0;
}