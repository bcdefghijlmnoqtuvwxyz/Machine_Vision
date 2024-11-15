#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 캐니 에지 검출기는 소벨 에지 검출 방법의 단점을 해결
// 그래디언트의 크기와 방향을 모두 고려하여 좀 더 정확한 에지 위치를 찾을 수 있음

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst1, dst2;
    Canny(src, dst1, 50, 100); // 낮은 임계값을 50, 높은 임계값을 100으로 설정
    Canny(src, dst2, 50, 150); // 낮은 임계값을 50, 높은 임계값을 150으로 설정
    // 임계값이 낮을수록 에지로 판별되는 픽셀이 더 많아짐

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();

    return 0;
}