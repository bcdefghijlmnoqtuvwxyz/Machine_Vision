#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 열기 연산은 입력 영상에 대하여 침식 연산을 수행한 후, 다시 팽창 연산을 수행
// 닫기 연산은 입력 영상에 대하여 팽창 연산을 수행한 후, 다시 침식 연산을 수행
// 이러한 연산들은 이미 연산이 한번씩 적용되기 때문에 객체 영역의 크기가 크게 바뀌지 않음
// 열기 연산은 침식 연산으로 픽셀 영역이 제거된 후 팽창, 작은 크기의 객체가 효과적으로 제거
// 닫기 연산은 팽창 연산으로 객체 내부 작은 구멍이 메워짐, 작은 구멍을 제거

int main()
{
    Mat src = imread("milkdrop.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat bin;
    threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU); // 오츠 알고리즘으로 자동 이진화

    Mat dst1, dst2;
    morphologyEx(src, dst1, MORPH_OPEN, Mat()); // 열기 연산
    morphologyEx(src, dst2, MORPH_CLOSE, Mat()); // 닫기 연산

    imshow("src", src);
    imshow("bin", bin);
    imshow("erode", dst1);
    imshow("dilate", dst2);

    waitKey();
    destroyAllWindows();

    return 0;
}