#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 원을 검출할 때 허프 그래디언트 방법(Hough gradient method)을 사용
// 두 단계로 구성되고 첫 단계는 영상에 존재하는 모든 원의 중심 좌표를 찾고, 두 단계는 검출된 원의 중심으로부터 적합한 반지름을 구함
// 중심 좌표를 찾는 과정에서 축적 배열이 사용됨

int main()
{
    Matt src = imread("coins.png", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat blurred;
    blur(src, blurred, Size(3, 3)); // 잡음을 제거하는 용도로 사용

    vector<Vec3f> circles;
    HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);
    // blurred = 원본 그레이스케일 영상, circles = 검출된 원 정보를 저장할 출력 벡터
    // HOUGH_GRADIENT = 이 것만 지정 가능, 1 = 입력 영상과 축적 배열 크기 비율, 50 = 인접한 원 중심의 최소 거리
    // 150 = Canny 에지 검출기의 높은 임계값, 30 = 축적 배열에서 원 검출을 위한 임계값
    // 두 원의 중심점 거리가 50픽셀보다 작으면 검출하지 않음

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    for(Vec3f c : circles) {
        Point center(cvRound(c[0]), cvRound(c[1]));
        int radius = cvRound(c[2]);
        circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}