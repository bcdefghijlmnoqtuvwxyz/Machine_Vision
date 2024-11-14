#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 필터링(filtering)이란 영상에서 원하는 정보만 통과시키고 원치 않는 정보는 걸러 내는 작업
// 부드러운 느낌의 성분을 제거하여 영상을 좀 더 날카로운 느낌이 나도록 만들 수 있음
// 영상의 필터링은 보통 마스크(mask)라고 부르는 작은 크기의 행렬을 이용
// 마스크는 필터링의 성격을 정의하는 행렬이며 커널(kernel), 윈도우(window)라고도 부르며 마스크 자체를 필터라고도 부르기도 함
// 마스크 행렬의 원소는 보통 실수로 구성, 3x3 행렬이 다양한 필터링 연산에서 가장 널리 사용됨
// 엠보싱 필터링은 픽셀 값 변화가 적은 평탄한 영역은 회색으로 설정

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed" << endl;
        return;
    }

    float data[] = {-1, -1, 0, -1, 0, 1, 0, 1, 1};

    Mat emboss(3, 3, CV_32FC1, data); // filter2D() 함수를 이용하여 3x3 크기의 엠보싱 필터 마스크 행렬 emboss를 생성
    Mat dst;

    filter2D(src, dst, -1, emboss, Point(-1, -1), 128); 
    // filter2D() 함수는 필터 마스크를 사용하는 일반적인 필터링 
    // Point(-1, -1)은 커널 행렬 중심 좌표를 고정점으로 사용함을 의미
    // 엠보싱 필터링을 수행, 6번째 인자에 128을 지정하여 필터링 결과 영상에 128을 더함

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}