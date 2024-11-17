#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 컬러 영상에서 자주 요구되는 기법은 특정 색상 영역을 추출하는 작업
// 색상 영역을 구분할 때에는 HSV 등 색상(H) 정보가 따로 설정되어 있는 색 공간을 사용하는 것이 유리
// HSV 색 공간에서 녹색은 H 값이 60 근방으로 표현되기 때문에 H 값이 60에 가까운지 조사하여 녹색 픽셀을 찾아낼 수 있음
// 행렬의 원소 값이 특정 범위 안에 있는지 확인하려면 inRange() 함수를 사용할 수 있음

int lower_hue = 40, upper_hue = 80; // 두 개의 트랙바 위치를 저장할 변수 선언
Mat src, src_hsv, mask;

void on_hue_changed(int, void*);

int main(int argc, char* argv[])
{
    src = imread("candies.png", IMREAD_COLOR);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    cvtColor(src, src_hsv, COLOR_BGR2HSV); // HSV 색 공간 변환

    imshow("src", src);

    namedwindow("mask");
    createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
    createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed); 
    // 색상의 최댓값을 179로 설정한 두 개의 트랙바를 생성, 콜백 함수를 강제로 호출
    
    on_hue_changed(0, 0);
    // 프로그램의 처음 실행 때 정상적인 출력이 가능하도록 트랙바 콜백 함수를 강제로 호출

    waitKey(0);

    return 0;
}

void on_hue_changed(int, void*)
{
    Scalar lowerb(lower_hue, 100, 0);
    Scalar upperb(upper_hue, 255, 255); // 임의로 채도는 100~255, 명도의 영향은 무시하도록 0에서 255로 설정
    inRange(src_hsv, lowerb, upperb, mask); // 색 성분 범위가 lowerb부터 upperb 사이인 위치의 픽셀만 흰색으로 설정한 mask 영상 생성

    imshow("mask", mask);
}