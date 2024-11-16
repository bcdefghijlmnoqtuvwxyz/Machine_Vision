#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 확률적 허프 변환(probabilistic Houghtransform)에 의한 직선 검출 방법
// 직선의 시작점과 끝점 좌표를 반환, 선분을 찾는 방법

int main()
{
    Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat edge;
    Canny(src, edge, 50, 100); // 캐니 에지 영상 edge 저장

    vector<Vec4i> lines;
    HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);
    // edge = 8비트 단일 채널 입력 에지 영상, lines = 선분의 시작점과 끝점의 정보를 저장할 출력 벡터
    // 1 = 축적 배열에서 해상도(픽셀), CV_PI / 180 = 축적 배열에서 해상도(라디안)
    // 160 = 축적 배열에서 직선으로 판단할 임계값, 50 = 검출할 선분의 최소 길이, 5 = 직선으로 간주할 최대 에지 점 간격

    Mat dst;
    cvtColor(edge, dst, COLOR_GRAY2BGR);

    for(Vec4i l : lines) { // 구해진 모든 직선 성분을 빨간색 직선으로 그림
        line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    destoryAllWindows();

    return 0;
}