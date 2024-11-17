#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// HSV는 색상(Hue), 채도(Saturation), 명도(value)로 색을 표현하는 방식 
// OpenCV에서 컬러 영상은 보통 uchar 자로형을 사용하고 세 개의 채널을 갖는 Mat 객체로 표현
// 컬러 영상을 다루다보면 빨간색 성분만을 이용하거나 HSV 색 공간으로 변환한 후 H 성분만을 이용하는 경우가 종종 발생
// 이러한 경우 3채널 Mat 객체를 1채널 Mat 객체 세 개로 분리해서 다루는 것이 효율적 

int main()
{
    Mat src = imread("candies.png"); // 컬러 영상

    if (src.empty()) {
        cerr << "Image load failed" << endl;
        return;
    }

    vector<Mat> bgr_planes;
    split(src, bgr_planes); 
    // bgr_planes에 src 영상의 채널을 분할

    imshow("src", src);
    imshow("B_plane", bgr_planes[0]); // 파란색 색상 평면
    imshow("G_plane", bgr_planes[1]); // 녹색 색상 평면
    imshow("R_plane", bgr_planes[2]); // 빨간색 색상 평면

    waitKey();
    destroyAllWindows();

    return 0;
}

// 예를 들어 파란색은 파란색 성분 값이 크기 때문에 B_plane에서 밝은 흰색으로 표시됨
// 노란색은 빨간색과 녹색 성분 값이 크기 때문에 R_plane과 G_plane 영상에서 밝게 표현됨, 반면 B_plane 영상에서는 어두운 검은색으로 표현됨