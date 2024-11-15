#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 널리 사용되는 영상의 기하학적 변환 중에는 어파인 변환보다 자유도가 높은 투시 변환(perspective transform)이 있음
// 투시 변환은 다양한 사각형 형태의 영상을 임의의 블록 사각형 형태로 변경할 수 있는 변환
// 좌표 계산의 편의상 3x3 행렬을 사용

Mat src;
Point2f srcQuad[4], dstQuad[4]; // 네 점 좌표 저장할 배열 선언

void on_mouse(int event, int x, int y, int flags, void* userdata);

int main()
{
    src = imread("card.bmp");

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("src");
    setMouseCallback("src", on_mouse); // 마우스 콜백 함수

    imshow("src", src);
    waitKey(0);

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) 
{
    static int cnt = 0; // 마우스 왼쪽 버튼이 눌린 횟수를 저장

    if(event == EVENT_LBUTTONDOWN) { // 마우스 왼쪽 버튼이 눌려질 때
        if(cnt < 4) {
            srcQuad[cnt++] = Point2f(x, y); // 마우스 왼쪽 버튼이 눌려진 좌표를 4개 저장

            circle(src, Point(x, y), 5, Scalar(0, 0, 255), -1); // 마우스 왼쪽 버튼이 눌려진 위치에 반지름이 5인 빨간색 원을 그림
            imshow("src", src);

            if(cnt == 4) { // 마우스 왼쪽 버튼이 5번 눌렸을 때
                int w = 200, h = 300; // 200x300의 영상

                dstQuad[0] = Point2f(0. 0); // 좌표 생성
                dstQuad[1] = Point2f(w - 1, 0);
                dstQuad[2] = Point2f(w - 1, h - 1);
                dstQuad[3] = Point2f(0, h - 1);

                Mat peres = getPerspectiveTransform(srcQuad, dstQuad); 
                // 투시 변환 행렬 저장, srcQuad는 입력 영상에서 네 점의 좌표, dstQuad는 결과 영상에서 네 젖ㅁ의 좌표를 의미

                Mat dst;
                warpPerspective(src, dst, pers, Size(w, h)); 
                // 투시 변환 결과 영상 생성, src는 입력 영상, dst는 결과 영상

                imshow("dst", dst);

                // 처음 실행될 때 src 창만 화면에 나타나고 이 후 좌측 상단 모서리 점부터 시계 방향 순서대로 좌표 클릭
                // 클릭한 위치는 빨간색 원으로 표시됨, 카드의 비율은 2:3 이기 때문에 200x300으로 영상 크기 설정
                // 결과 dst 창에 다이아 K 카드가 투시 변환되어 나타남
            }
        }
    }
}
