#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

    rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2); // 사각형을 두께 2인 선으로 그림(빨간색)
    rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1); // 사각형을 내부를 채워서 그림(갈색)

    circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA); // 반지름 30인 원을 내부를 채워서 그림(하늘색)
    circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA); // 반지름 60인 원을 두께 3인 선으로 그림(파란색)

    ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA); 
    // 타원을 0~270도까지 내부를 채워서 그림(하늘색)
    ellipse(img, Point(120, 300), Size(100, 30), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA); 
    // 타원을 두꼐 2인 선으로 그림(녹색)

    vector<Point> pts; // 계단 모양의 다각형을 두께 2인 선으로 그림(보라색)
    pts.push_back(Point(250, 250)); pts.push_back(Point(300, 250));
    pts.push_back(Point(300, 300)); pts.push_back(Point(350, 300));
    pts.push_back(Point(350, 350)); pts.push_back(Point(250, 350));
    polylines(img, pts, true, Scalar(255, 0, 255), 2);

    imshow("img", img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}