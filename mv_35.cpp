#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 영상의 기하학적 변환(geometric transform)은 영상을 구성하는 픽셀의 배치구조를 변경함으로써 전체 영상의 모양을 바꾸는 작업
// 픽셀 값은 그대로 유지하며 위치를 바꾸는 작업
// 어파인 변환(affine transformation)은 영상을 평행 이동시키거나 회전, 크기 변환 등을 통해 만들 수 있는 변환을 통칭
// 결과 영상 크기 및 모양을 변경할 수 있음, 3개의 점의 이동으로 정의할 수 있음

int main()
{
    Mat src = imread("tekapo.bmp"); // 3채널 컬러 영상으로 부름

    if(src.empty) {
        cerr << "image load failed!" << endl;
        return;
    }

    Point2f srcPts[3], dstPts[3]; // 세 점 좌표를 저장할 배열 선언
    srcPts[0] = Point2f(0, 0); // 좌측 상단
    srcPts[1] = Point2f(src.cols - 1, 0); // 우측 상단
    srcPts[2] = Point2f(src.cols - 1, src.rows - 1); // 우측 하단
    srcPts[0] = Point2f(50, 50); // 좌측 상단
    srcPts[1] = Point2f(src.cols - 100, 100); // 우측 상단
    srcPts[2] = Point2f(src.cols - 50, src.rows - 50); // 우측 하단

    Mat M = getAffineTransform(srcPts, dstPts); // 2x3 어파인 변환 행렬 저장
    
    Mat dst;
    warpAffine(src, dst, M, Size()); 
    // 어파인 변환 행렬 M을 이용, dst에 저장, Size()는 dst 영상 크기가 src 영상 크기와 같아지도록 설정

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();

    return 0;
}