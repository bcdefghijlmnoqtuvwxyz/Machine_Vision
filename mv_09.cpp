#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std;

// Scalar 클래스는 보통 4개 이하의 채널을 갖는 영상의 픽셀 값을 표현하는 용도로 사용
// 그레이스케일 영상의 경우, 첫 번째 원소가 픽셀 밝기, 나머지 세 개의 원소는 0으로 설정됨
// 트루컬러 영상의 경우, 처음 세 개의 원소가 B, G, R로 표현되고 네 번째 원소는 0으로 설정됨


int main()
{
    Scalar gray = 128; // 밝기 표현, gray 객체의 val 멤버 변수에 [128, 0, 0, 0] 값이 저장됨
    cout << "gray: " << gray << endl; 

    Scalar yellow(0, 255, 255); // 노란색, [0, 255, 255, 0]값이 저장됨
    cout << "yellow: " << yellow << endl;

    Mat img1(256, 256, CV_8UC3, yellow); // 256x256의 노란색 컬러 영상

    for (int i = 0; i < 4; i++) 
        cout << yellow[i] << endl; // 객체에 저장된 값 4개 참조

    return 0;
}