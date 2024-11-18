#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// HSV 색 공간에서 H 값을 이용하는 방식은 빨간색, 녹색, 노란색 등 원색에 가까운 색상을 찾기에는 효과적
// 하지만 사람의 피부색처럼 미세한 변화가 있거나 색상 값을 수치적으로 지정하기 어려운 경우 적합하지 않음
// 영상에서 컬러 히스토그램 정보를 이용하여 비슷한 색상 영역을 찾을 수 있음
// 기준 영상으로부터 컬러 히스토그램을 미리 구하고 주어진 영상에서 해당 히스토그램에 부합하는 영역을 찾아내는 방식
// 이처럼 주어진 히스토그램 모델과 일치하는 픽셀을 찾아내는 기법을 히스토그램 역투영(histogram backprojection)dlfkrh gka
// 예를 들어 피부색에 대한 색상 히스토그램을 가지고 있다면 역투영 방법을 사용하여 영상의 피부색 영역을 검출할 수 있음

int main()
{
    Mat ref, ref_ycrcb, mask;
    ref = imread("ref.png", IMREAD_COLOR);
    mask = imread("mask.bmp", IMREAD_GRAYSCALE);
    cvtColor(ref, ref_ycrcb, COLOR_BGR2YCrCb);

    Mat hist;
    int channels[] = {1, 2};
    int cr_bins = 128; 
    int cb_bins = 128;
    float cr_range[] = {0, 256};
    float cb_range[] = {0, 256};
    const float* ranges[] = {cr_range, cb_range}; 
    // 기준 영상에서 피부색 영역의 CrCb 2차원 히스토그램을 계산하여 hist에 저장

    calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);

    Mat src, src_ycrcb;
    src = imread('kids.png', IMREAD_COLOR);
    cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb); // 입력 영상 호출 및 변환

    Mat backproj;
    calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges, 1, true); // 히스토그램 역투영 결과를 backproj에 저장
    // src_ycrcb = 입력 영상의 배열 또는 주소, 배열의 경우 모든 영상의 크기와 깊이는 같아야 함
    // 1 = 입력 영상 개수, channels = 역투영 계산 시 사용할 채널 번호 배열, hist = 입력 히스토그램
    // backproj = 출력 히스토그램 역투영 영상, 입력 영상과 같은 크기 및 깊이를 갖는 1채널 행렬
    // ranges = 각 차원의 히스토그램 빈 범위를 나타내는 배열의 배열
    // 1 = 히스토그램 역투영 값에 추가적으로 곱할 값, true = 히스토그램 빈의 간격이 균등한지 나타내는 플래그

    imshow("src", src);
    imshow("backproj", backproj);

    waitKey(0);

    return 0;
}
// 결과 영상으로 피부색 부분이 흰색으로 나타내는 것을 알 수 있음