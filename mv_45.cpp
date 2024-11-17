#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// equalizehist() 함수는 그레이스케일 영상만 입력으로 받아 히스토그램 평활화를 수행할 수 있고
// 3채널 컬러 영상은 영상의 밝기 정보만을 사용해야 함, 밝기 정보와 색상 정보로 분리하여 밝기 정보에 대해서만 히스토그램 평활화를 수행
// YCrCb 색 공간에서 Y 성분은 밝기 또는 휘도 정보를 나타냄, Cr, Cb 성분은 색상 또는 색차 정보를 나타냄
// Y 성분에 대해서만 히스토그램 평활화를 수행하고 Cr과 Cb 색 성분은 그대로 유지하고 다시 합침

int main()
{
    Mat src = imread("pepper.bmp", IMREAD_COLOR);

    if(src.empty()) {
        cerr << "Image load failed" << endl;
        return -1;
    }

    Mat src_ycrcb;
    cvtColor(src, src_ycrcb, COLOR_BRG2YCrCb);

    vector<Mat> ycrcb_planes;
    spiit(src_ycrcb, ycrcb_planes); // 채널을 분리하여 ycrcb_planes에 저장

    equalizeHist(ycrcb_planes[0], ycrcb_planes[0]); // Y 채널에 대해서만 히스토그램 평활화 

    Mat dst_ycrcb;
    merge(ycrcb_planes, dst_ycrcb); // 세 개로 분리된 영상을 합쳐서 새 영상 생성

    Mat dst;
    cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR); // 영상의 색 공간을 BGR 색 공간으로 변환하여 dst에 저장

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);

    return 0;
}

// 원본 영상의 색감은 유지한 채 명암비가 높아진 것을 확인할 수 있음