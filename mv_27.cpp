#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat src1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
    Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

    if(src1.empty() || src2.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src1", src1);
    imshow("src2", src2);

    Mat dst1, dst2, dst3, dst4;

    bitwise_and(src1, src2, dst1); // 두 입력 비트가 1일때 결과가 1
    bitwise_or(src1, src2, dst2); // 두 입력 비트 중 하나라도 1일때 결과가 1
    bitwise_xor(src1, src2, dst3); // 두 입력 비트의 값들이 서로 다를 때 결과가 1
    bitwise_not(src1, dst4); // src1의 입력 비트의 반대값

    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);
    imshow("dst4", dst4);

    waitKey();

    return 0;
}