#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// 샤프닝(sharpening)이란 영상을 날카로운 느낌이 나도록 변경하는 필터링 기법
// 날카로운 느낌의 영상은 초점이 잘 맞은 사진처럼 객체의 윤곽이 뚜렷하게 구분되는 영상을 의미
// 블러링된 영상을 사용하여 샤프닝을 구현함, 여기서 블러링이 적용된 영상을 언샤프(unsharp)라고 함
// 언샤프한 영상을 이용하여 역으로 날카로운 영상을 생성하는 필터를 언샤프 마스크 필터(unsharp mask filter)라고 함

int main()
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    imshow("src", src);

    for(int sigma = 1; sigma <= 5; sigma++) { 
        // 가우시안 필터의 표준 편차 냐흠 값을 증가시키면서 언샤프 마스크 필터링을 수행
        // sigma 값이 증가할수록 더 뚜렷해짐

        Mat blurred;
        GaussianBlur(src, blurred, Size(), sigma);

        float alpha = 1.f;
        Mat dst = (1 + alpha) * src - alpha * blurred; // 언샤프 마스크 필터링을 수행

        String desc = format("sigma: %d", sigma);
        putText(dst, desc, Point(10. 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }

    destroyAllWindows();

    return 0;
}