#include "opencv2/opencv.hpp" // 다양한 클래스와 함수가 선언되어 있는 헤더 파일
#include <iostream> // C++ 표준 출력을 위해 헤더 파일 포함

using namespace cv; // cv:: 생략 가능하게 함
using namespace std; // std:: 생략 가능하게 함

int main() 
{
    cout << "Hello OpenCV " << CV_VERSION << endl; 
    // CV_VERSION은 매크로로 정의되어 있어 설치된 OpenCV 라이브러리의 버전 정보 출력

    Mat img; // Mat 클래스 타입의 변서 img 선언
    img = imread("lenna.bmp"); 
    // imread() 함수는 image read(영상 읽기)를 의미

    if(img.empty()) { // imread()가 실행이 안될 때 empty() 함수는 true(1)을 반환
        cerr << "Image load failed!" << endl;
        return -1;
    }

    nameWindow("image"); 
    // namedWindow() 함수는 영상을 화면에 나타내기 위한 새로운 창을 생성, 'image'라는 이름을 부여

    imshow("image", img); 
    // imshow() 함수는 image show(영상 보여 주기)를 의미, 'image'라는 이름 창에 img 객체가 가지고 있는 lenna.bmp 영상을 출력

    waitKey(0); // waitKey() 함수는 사용자의 키보드 입력을 기다리는 함수, 사용자가 키보드를 누르기 전까지 영상을 화면에 나타나게 함

    return 0;
}