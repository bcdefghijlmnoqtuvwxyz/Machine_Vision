#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 모폴로지(morphology)는 형태 또는 모양에 관한 학문을 의미
// 영상 처리 분야에서 모폴로지는 영상에서 객체의 형태 및 구조에 대해 분석하고 처리하는 기법을 의미, 수학적 모폴로지라고도 함
// 모폴로지 기법은 그레이스케일 영상과 이진 영상에 대하여 모두 적용할 수 있지만, 주로 이진 영상에서 객체의 모양을 단순화하거나 잡음을 제거하는 등 용도로 사용됨
// 모폴로지 연산을 정의하려면 먼저 구조 요소(structuring element)를 정의해야 함
// 구조 요소는 마치 필터링에서 사용되는 마스크처럼 모폴로지 연산의 동작을 결정하는 작은 크기의 행렬
// 필요에 따라 원하는 구조 요소를 선택 및 사용할 수 있지만 대부분 3x3 정방형 구조 요소를 사용, 구조 요소의 중심을 고정점으로 사용
// 침식과 팽창 연산을 수행, 침식은 깎고 팽창은 확장

int main()
{
    Mat src = imread("milkdrop. bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat bin;
    threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU); // 오츠 알고리즘으로 자동 이진화를 수행, 결과를 bin에 저장

    Mat dst1, dst2;
    erode(bin, dst1, Mat()); // 3x3 정방형 구조 요소를 이용 침식 연상 수행, 결과를 dst1에 저장
    dilate(bin, dst2, Mat()); // 3x3 정방형 구조 요소를 이용 팽창 연산 수행, 결과를 dst2에 저장

    imshow("src", src);
    imshow("bin", bin);
    imshow("erode", dst1); // 흰색 영역 축소, 객체 내부 검은색 영역 확대
    imshow("dilate", dst2); // 흰색 영역 확대

    waitKey();
    destroyAllWindows();

    return 0;
}