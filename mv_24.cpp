#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 히스토그램 스트레칭(histogram stretching)은 영상의 히스토그램이 
// 그레이스케일 전 구간에 걸쳐서 나타나도록 변경하는 선형 변환 기법
// 명암비가 낮은 영상은 히스토그램이 특정 구간에 집중되어 나타나게 됨,
// 이 것을 그레이스케일 전 구간에서 고무줄 늘리듯이 전 구간에 나타나도록 변환하는 기법

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed" << endl;
        return;
    }

    double gmin, gmax;
    minMaxLoc(src, &gmin, &gmax); // 그레이스케일 최솟값과 최댓값을 구하여 저장

    Mat dst = (src - gmin) * 255 / (gmax - gmin); // 히스토그램 스트레칭 수식을 적용하여 결과 영상 생성

    imshow("src", src);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src))); 
    // getGrayHistImage() 함수는 히스토그램 그래프에서 최대 빈도수를 표현하는 막대그래프 길이를 설정함
    // calcGrayHist() 함수는 그레이스케일 입력 영상으로부터 256개의 빈으로 구성된 히스토그램을 생성

    imshow("dst", dst);
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

    waitKey();
    destroyAllWindows();

    return 0;
}