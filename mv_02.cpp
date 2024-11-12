#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main() 
{
    Mat img1; // empty matrix

    Mat img2(480, 640, CV_8UC1); // 480x640, CV_8U = uchar 자료형을 의미, C1 = Channel1을 의미
    Mat img3(480, 640, CV_8UC3); // Channel을 3개 가졌다는 의미, Blue, Green, Red를 여기에 사용
    Mat img4(Size(640, 480), CV_8UC3); // 640x480 3Channel

    Mat img5(480, 640, CV_8UC1, Scalar(128)); // 그레이스케일 영상 128의 값
    Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255)); // 3Channel 컬러 영상 B, G, R 중 Red의 색상 성분

    Mat mat1 = Mat::zeros(3, 3, CV_32SC1); // zeros는 모든 원소가 0으로 초기화된 행렬을 생성
    Mat mat2 = Mat::ones(3, 3, CV_32SC1); // ones는 모든 원소가 1로 초기화된 행렬을 생성
    Mat mat3 = Mat::eye(3, 3, CV_32SC1); // eye는 단위 행렬을 생성

    float data[] = {1, 2, 3, 4, 5, 6};
    Mat mat4(2, 3, CV_32FC1, data); // 2x3의 float 자료형의 Channel 1개 생성
                                    // 1, 2, 3
                                    // 4, 5, 6

    Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
    Mat mat6 = Mat_<uchar> ({2, 3}, {1, 2, 3, 4, 5, 6}); // 2x3의 uchar 자로형의

    mat4.create(256, 256, CV_8UC3); // create() 함수는 새로 만들 행렬의 크기 또는 타입이 기존과 다를 경우,
                                    // 기존 메모리 공간을 해제한 후 새로운 메모리 공간을 할당
    mat5.create(4, 4, CV_32FC1);

    mat4 = Scalar(255, 0, 0); // 모든 픽셀을 Blue로 설정
    mat5.setTo(1.f); // 모든 원소 값을 1.f로 설정

    return 0;
}