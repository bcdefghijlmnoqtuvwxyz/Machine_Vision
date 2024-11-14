#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 신호 처리 관점에서 잡음(noise)이란 원본 신호에 추가된 원치 않은 신호를 의미
// 영상을 획득하는 과정에서 발생,
// 디지털 카메라에서 사진을 촬영하는 경우 광학적 신호를 전기적 신호로 변환하는 센서(sensor)에서 주로 잡음이 추가됨
// 잡음이 생성되는 방식을 잡음 모델(noise model)이라고 함
// 대표적으로 가우시안 잡음 모델(Gaussian noise model)이 있고 평균이 0인 가우시안 분포를 따르는 잡음을 의미

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    imshow("src", src);

    for(int stddev = 10; stddev <= 30; stddev += 10) { // 표준 편차 stddev 값이 증가, 값이 증가할수록 영상이 지저분해짐
        Mat noise(src.size(), CV_32SC1);
        randn(noise, 0, stddev); 
        // 평균이 0이고 표준 편차가 stddev인 잡음을 생성하여 noise 행렬에 저장
        // noise 행렬은 부호 있는 정수형을 사용

        Mat dst;
        add(src, noise, dst, Mat(), CV_8U);

        String desc = format("stddev = %d", stddev);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }
    destroyAllWindows();

    return 0;
}