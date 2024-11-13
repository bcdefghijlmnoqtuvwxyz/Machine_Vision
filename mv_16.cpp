#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

Mat img;
Point ptO1d;
void on_mouse(int event, int x, int y, int flags, void*);

int main()
{
    img = imread("lenna.bmp");

    if(img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img"); // 창 미리 생성
    setMouseCallback("ing", on_mouse); // 마우스 콜백 함수 선언 및 등록

    imshow("img", img);
    waitKey(0);

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*)
{
    switch(event) {
        case EVENT_LBUTTONDOWN: // 마우스 왼쪽 버튼을 누른 경우
            ptO1d = Point(x, y); // 좌표 저장
            cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
            break;
        case EVENT_LBUTTONUP: // 마우스 왼쪽 버튼을 떼는 경우
            cout << "EVENT_LBUTTONDUP: " << x << ", " << y << endl;
            break;
        case EVENT_MOUSEMOVE: // 마우스가 창 위에서 움직이는 경우
            if(flags & EVENT_FLAG_LBUTTON) { // 마우스 왼쪽 바튼이 눌려 있음
                line(img, ptO1d, Point(x, y), Scalar(0, 255, 255), 2); // 노란색 직선을 그림
                imshow("img", img);
                ptO1d = Point(x, y);
            }
            break;
        default:
            break;
    }
}