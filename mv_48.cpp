#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

void on_threshold(int pos, void* userdata);

// 영상의 이진화(binarization)는 영상의 각 픽셀을 두 개의 부류로 나누는 작업
// 예를 들어 입력 영상을 주요 객체 영역과 배경 영역으로 나누거나 또는 영상에서 중요도가 높은 관심 영역과 그렇지 않은 비관심 영역으로 구분하는 용도로 사용될 수 있음
// 디지털 컴퓨팅 분야에서 이진화는 0 또는 1로 설정하지만 영상의 이진화는 픽셀 값을 0 또는 255로 설정
// 이진화가 적용된 이진 영상은 보통 흰색과 검은색 픽셀로만 구성됨

int main(int argc, char* argv[]) // 프로그램 실행 시 명령행 인자를 받을 수 있도록 지정
{
    Mat src;

    if(argc < 2) // 명령행 인자 개수가 2보다 작으면
        src = imread("neutrophils.png", IMREAD_GRAYSCALE);
    else // 만약 프로그램 실행 파일 이름 뒤에 사용할 영상 파일 이름을 명시하면
        src = imread(argv[1], IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src);

    namedWindow("dst");
    createTrackbar("threshold", "dst", 0, 255, on_threshold, (void*)&src); // 트랙바 생성
    setTrackbarPos("Threshold", "dst", 128); 
    // 프로그램이 처음 실행될 때, 트랙바 위치가 128이 되도록 설정하여 on_threshold() 함수가 처음에 한번 실행되도록 함

    waitKey();

    return 0;
}

void on_threshold(int pos, void* userdata)
{
    Mat src = *(Mat*)userdata; // userdata를 Mat*로 형변환 후 src 변수로 참조

    Mat dst;
    threshold(src, dst, pos, 255, THRESH_BINARY); // threshold() 함수는 이진화 수행 함수
    // pos = 임계값, 255 = THRESH_BINARY를 사용할 때 결과 영상의 최댓값

    imshow("dst", dst);
}