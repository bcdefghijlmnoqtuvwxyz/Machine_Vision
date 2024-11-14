#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 히스토그램 평활화(histogram equalization)는 히스토그램 스트레칭과 더불어
// 영상의 픽셀 값 분포가 그레이스케일 전체 영역에서 골고루 나타나도록 변경하는 알고리즘
// 히스토그램 그래프에서 특정 그레이스케일 값 근방에서 픽셀 분포가 너무 많이 뭉쳐 있는 경우 이를 넓게 펼쳐 주는 방식

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed" << endl;
        return;
    }

    Mat dst;
    equalizeHist(src, dst); // equalizeHist() 함수는 그레이스케일 영상의 히스토그램 평활하를 수행

    imshow("src", src);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src)));

    imshow("dst", src);
    imshow("dstHist", getGrayHistImage(calcGrayHist(src)));

    waitKey();
    destroyAllWindows();

    return 0;
}