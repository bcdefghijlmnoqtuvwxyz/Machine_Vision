#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

void on_level_change(int pos, void* userdata);

int main()
{
    Mat img = Mat::zeros(400, 400, CV_8UC1);

    namedWindow("image"); // 창 미리 생성
    createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);
    // 트랙바 이름은 level이고, 최대 단계는 16으로 지정

    imshow("image", img);

    waitKey(0);

    return 0;
}

void on_level_change(int pos, void* userdata)
{
    Mat img = *(Mat*)userdata; // void* 타입의 인자 userdata를 Mat* 타입으로 형변환 후 img 변수로 참조

    img.setTo(pos * 16); // pos에 16을 곱한 결과를 전체 img 영상의 픽셀 값으로 설정, 255보다 크면 포화 연산이 적용
    imshow("image", img);
}