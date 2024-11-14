#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 블러링(blurring)은 마치 초점이 맞지 않는 사진처럼 영상을 부드럽게 만든느 필터링 기법, 스무딩(smoothing)이라고도 함
// 거친 느낌의 입력 영상을 부드럽게 만든느 용도로 사용하거나, 영상에 존재하는 잡음의 영향을 제거하는 전처리 과정으로도 사용
// 평균값 필터는 마스크의 크기가 커지면 커질수록 더욱 부드러운 느낌의 결과 영상을 생성, 대신 연산량이 크게 증가

int main()
{
    Mat src = inread("lenna.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    imshow("src", src);

    Mat dst;

    for(int ksize = 3; ksize <= 7; ksize += 2) {
        blur(src, dst, Size(ksize, ksize)); // blur() 함수를 이용하여 평균값 필터링을 수행할 수 있음

        String desc = format("Mean: %dx%d", ksize, ksize); // 필터 크기가 커질수록 결과 영상이 더욱 부드럽게 변경됨
        putText(dst, desc, Poing(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey(0);
    }

    destroyAllWindows();

    return 0;
}