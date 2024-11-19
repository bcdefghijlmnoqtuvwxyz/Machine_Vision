#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 전역 이진화(global binarization)는 영상의 모든 픽셀에 같은 임계값을 적용하여 이진화를 수행하는 방식
// 균일하지 않은 조명 환경에서 촬영된 영상에 대해 전역 이진화를 수행하면 객체와 배경이 적절하게 분리되지 않는 경우가 발생
// 적응 이진화(adaptive binarization)는 각 픽셀마다 서로 다른 임계값을 사용하여 효과적
// 적응 이진화는 모든 픽셀에서 정해진 크기의 사각형 블록 영역을 설정, 블록 영역 내부의 픽셀 값 분포로부터 고유의 임계값을 결정하여 이진화하는 방식

void on_trackbar(int pos, void* userdata);

int main()
{
    Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);

    if(src. empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src);

    namedWindow("dst");
    createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src); // 트랙바 생성
    setTrackbarPos("Block Size", "dst", 11); // 초기 위치를 11로 지정

    waitKey(0);

    return 0;
}

void on_trackbar(int pos, void* userdata) 
{
    Mat src = *(Mat*)userdata;

    int bsize = pos;
    if(bsize % 2 == 0) bsize--; // 짝수이면 1을 빼서 홀수로 만듬
    if(bsize < 3) bsize = 3; // 3보다 작으면 3으로 설정

    Mat dst;
    adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5); // 가우시안 가중 평균을 사용
    // 255 = 이진화 결과 영상의 최댓값, ADAPTIVE_THRESH_GAUSSIAN_C = 블록 평균 계산 방법 지정
    // bsize = 임계값 계산 시 사용하는 블록 크기, 3보다 같거나 큰 홀수를 지정해야 함, 5 = 임계값 조정을 위한 상수, 블록 평균에서 5를 뺀 값을 임계값으로 사용

    imshow("dst", dst);
}
// 스도쿠 글씨와 사각형 외곽선이 검은색으로 이진화되어 구분이 잘됨
// 블록 크기 51로 설정한 결과로 더 선명해짐