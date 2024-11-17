#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 컬러 영상의 한 픽셀을 정확하게 표현하려면 Vec3b 자료형을 이용해야 함
// Vec3b 클래스는 크기가 3인 uchar 자로형 배열을 멤버 변수로 가지고 있는 클래스
// Vec3b 클래스의 바이트 크기는 3바이트
// 컬러 영상에서 픽셀 값을 참조할 떄 Mat::at() 함수를 사용하고, 사용하려면 Vec3b 자로형을 명시해야 함
// 에를 들어 영상을 저장하고 있는 img 객체에서 (0. 0)위치의 픽셀 값을 참조하려면 Vec3b& pixel = img.at<Vec3b>(0, 0)으로 코드 작성

int main()
{
    Mat src = inread("butterfly.jpg", IMREAD_COLOR); // 컬러 영상

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst(src.rows, src.cols, src.type()); // src 영상 복사

    for (int j = 0; j < src.rows; j++) {
        for (int i = 0; i < src.cols; i++) {
            Vec3b& p1 = src.at<Vec3b>(j, i); // i, j 좌표 픽셀 값을 p1, p2에 참조로 받아옴
            Vec3b& p2 = dst.at<Vec3b>(j, i);

            p2[0] = 255 - p1[0]; // Blue
            p2[0] = 255 - p1[0]; // Green
            p2[0] = 255 - p1[0]; // Red
        }
    }

    imshow("src", src); // 정상 영상
    imshow("dst", dst); // 반전 영상

    waitKey();
    destoryAllWindows();

    return 0;
}