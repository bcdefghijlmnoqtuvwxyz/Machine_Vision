#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed" << endl;
        return;
    }

    Mat edge;
    Canny(src, edge, 50, 150); // 캐니 에지 검출기로 에지 영상을 edge에 저장

    vector<Vec2f> lines;
    HoughLines(edge, lines, 1, CV_PI / 180, 250); // 1은 픽셀 단위 해상도, lines에 저장

    Mat dst;
    cvtColor(edge, dst, COLOR_GRAY2BGR); 
    // 그레이스케일 edge를 BGR 3채널 컬러 영상을 변환하여 dst에 저장

    for(size_t i = 0; i < lines.size(); i++) {
        float r = lines[i][0], t = lines[i][1];
        // 원점에서 직선까지의 수직 거리 p를 변수 r에
        // 원점에서 직선에 수직선을 내렸을 때 x축과 이루는 각도인 q를 변수 t에 저장

        double cos_t = cos(t), sin_t = sin(t);
        double x0 = r * cos_t, y0 = r * sin_t; // 원점에서 직선에 수선을 내렸을 때 만나는 점의 좌표
        double alpha = 1000;

        Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
        Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
        line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA); // 빨간색 실선
    }

    imshow("srt", srt);
    imshow("dst", dst);

    waitKey(0);
    destroyAllwindows();

    return 0;
}