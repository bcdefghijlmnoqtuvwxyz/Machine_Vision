#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main() 
{
    Mat img1 = imread("lenna.bmp");

    cout << "Width: " << img1.cols << endl; // 가로 크기 출력
    cout << "Height: " << img1.rows << endl; // 세로 크기 출력
    cout << "Channels: " << img1.channels() << endl; // 채널 수 출력

    if(img1.type() == CV_8UC1) // 그레이스케일 영상 
        cout << "img1 is a grayscale image." << endl;
    else if(img1.type() == CV_8UC3) // 3채널 트루컬러 영상 
        cout << "img1 is a truecolor image." << endl; 
        // imread() 함수의 두 번째 인자를 설정하지 않아 이 문장이 출력됨

    // Mat 클래스에 저장된 객체가 영상이라면 imshow() 함수를 사용 
    // Mat에 int, float 같은 자료형의 행렬이 저장되어 있으면 사용이 적절치 않음

    float data[] = {2.f, 1.414f, 3.f, 1.732f};
    Mat mat1(2, 2, CV_32FC1, data); // 2x2 행렬의 data 정보 참조
    cout << "mat1:\n" << mat1 << endl; //[2, 1.414;
                                       // 3, 1.732]가 출력됨
                                       // 원소는 , 행은 ;로 구분됨
    return 0;
}