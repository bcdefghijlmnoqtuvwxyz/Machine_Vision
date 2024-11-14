#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 대부분의 영상에는 가우시안 잡음이 포함되어 있으며 많은 컴퓨터 비전 시스템이 
// 가우시안 잡음을 제거하기 위해 가우시안 필터를 사용
// 픽셀 값이 급격하게 변경되는 에지 근방에 동일한 가우시안 필터가 적용되면 잡음 뿐만 아니라 에지 성분까지 감소하게 됨
// 이는 객체의 윤곽이 흐릿하게 바뀌는 것을 의미하고 이를 극복하기 위한 알고리즘으로 양방향 필터(bilateral filter)가 있음

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat noise(src.size(), CV_32SC1);
    randn(noise, 0, 5); // 평균이 0이고 표준 편차가 5인 가우시아 잡음 추가
    add(src, noise, src, Mat(), CV_8U);

    Mat dst1;
    Gaussianblur(src. dst1, Size(), 5); // 가우시안 필터링 수행

    Mat dst2;
    bilateralFilter(src, dst2, -1, 10, 5); 
    // 양수가 아닌 값(-1)이면 좌표 공간에서 자동 계산
    // 색 공간 표준 편차 10, 좌표 공간의 표준 편차인 5인 양방향 필터링 수행

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();

    return 0;
}