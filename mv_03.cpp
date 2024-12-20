#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv;
using namespace std;

int main()
{
    Mat img1 = imread("lenna.bmp");

    Mat img2 = img1; // 복사 생성자(얕은 복사), 하나의 영상을 공유하는 형태
    Mat img3;
    img3 = img1; // 대입 연산자(얕은 복사)

    Mat img4 = img1.clone(); // 깊은 복사, 자기 자신과 동일한 Mat 객체를 완전히 새로 만듬
    Mat img5;
    img1.copyTo(img5); // 깊은 복사, 
    // 크기 및 타입이 같으면 원소 값 복사만 수행, 다르면 copyTo() 함수 내부에서 행렬을 새로 생성한 후 픽셀 값 복사

    img1.setTo(Scalar(0, 255, 255)); // img1의 모든 픽셀을 yellow로 설정

    namedWindow("image");

    imshow("img1", img1); // yellow
    imshow("img2", img2); // yellow, 얕은 복사
    imshow("img3", img3); // yellow, 얕은 복사
    imshow("img4", img4); // 정상 출려, 깊은 복사
    imshow("img5", img5); // 정상 출력, 깊은 복사

    waitKey();
    destroyAllWindows();

    return 0;
}