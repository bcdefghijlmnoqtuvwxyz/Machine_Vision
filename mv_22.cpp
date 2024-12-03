#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 히스토그램(histogram)이란 영상의 픽셀 값 분포를 그래프 형태로 표현한 것
// 각 픽셀의 밝기를 막대 그래프의 수로 나타내는데 이 가로축을 빈(bin)이라고 함
// 그레이스케일 영상의 경우 256개의 빈을 갖는 히스토그램이 일반적임

Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);
    // CV_Assert() 함수를 이용하여 그레이스케일 영상인지 검사,
    // 그레이스케일 영상이 아니면 에러가 발생하고 프로그램 종료

    Mat hist;
    int channels[] = {0}; // 그레이스케일 영상은 한 개의 채널이고, 채널 번호는 0부터 시작하므로 배열은 0
    int dims = 1; // 1차원 행렬을 의미
    const int histSize[256]; // 채널 값의 범위를 256개 빈으로 나누어 구하겠다는 의미
    float graylevel[] = {0, 256}; // 그레이스케일 영상의 최솟값과 최댓값 지정
    const float* ranges[] = {graylevel}; // graylevel 배열 이름을 원소로 갖음

    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
    
    return hist;
}