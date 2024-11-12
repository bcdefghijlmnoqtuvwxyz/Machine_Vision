#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat img1 = imread("lenna.bmp");

    if(img1.empty()) {
        cer << "Image load failed!" << endl;
        return;
    }

    // Rect() 함수는 관심 영역(ROI, Region Of Interest)을 설정하는 용도로 사용
    // ROI는 영상 전체 영역 중 특정 영역에 대한 영상 처리를 설정

    Mat img2 = img1(Rect(220, 120, 340, 240)); // 얕은 복사, img1 영상의 (220, 120) 좌표부터 340x240 크기만큼의 사각형 부분에서 영상을 추출
                                               // 부분 영상 픽셀 값을 변경하면 원본 영상 픽셀 값도 변경됨

    Mat img3 = img1(Rect(220, 120, 340, 240)).clone(); // clone() 함수는 독립된 메모리 영역을 확보하여 부분 영상을 추출할 때 사용
                                                       // 부분 영상 픽셀 값을 변경해도 원본 영상은 변경되지 않음

    img2 = ~img2; // 영상 반전

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);

    waitKey();
    destroyAllWindows();

    return 0;
}