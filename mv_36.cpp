#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat src = imread("lenna.bmp");

    if(src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat M = Mat_<double>({2, 3}, {1, 0, 150, 0, 1, 100});
    // 가로 150픽셀, 세로 100픽셀 이동하는 어파인 변환 행렬 M 생성
    Mat dst;
    warpAffine(src, dst, M, Size()); // warpAffine() 함수는 영상을 이동 변환


    double mx = 0.3;
    Mat M = mat_<double>({2, 3}, {1, mx, 0, 0, 1, 0});
    // 가로 방향으로 밀림 정도를 0.3으로 설정한 전단 변환 행렬 M 생성
    Mat dst;
    warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows)); 
    // 입력 영상의 일부가 잘리지 않도록 영상 가로 크기를 조절
    imshow("src", src);
    imshow("dst", dst);


    Mat dst1, dst2, dst3, dst4;
    resize(src, dst1, Size(), 4, 4, INTER_NEAREST); // 최근방 이웃 보간법
    // x, y 방향으로 4배 확대, src가 480x320이므로 1920x1280으로 결정
    resize(src, dst2, Size(1920, 1280)); // 양선형 보간법, 기본값, 연산 속도도 빠르고 화질도 충분히 좋아 널리 사용됨
    resize(src, dst2, Size(1920, 1280), 0, 0, INTER_CUBIC); // 3차 보간법, 좋은 화질
    resize(src, dst2, Size(1920, 1280), 0, 0, INTER_LANCZOS4); // 란초스 보간법, 좋은 화질

    imshow("src", src);
    imshow("dst1", dst1(Rect(400, 500, 400, 400))); // 400x500 좌표에서 400x400 크기의 부분 영상 출력
    imshow("dst2", dst2(Rect(400, 500, 400, 400)));
    imshow("dst3", dst3(Rect(400, 500, 400, 400)));
    imshow("dst4", dst4(Rect(400, 500, 400, 400)));
    
    
    Point2f cp(src.cols / 2.f, src.rows / 2.f); // 영상의 중심 좌표를 가리키는 변수 선언
    Mat M = getRotationMatrix2D(cp, 20, 1); 
    // 좌표를 기준으로 반시계 방향으로 20도 회전하는 변환 행렬 생성
    // 시계 방향은 -20

    Mat dst;
    warpAffine(src, dst, M, Size());

    imshow("src", src);
    imshow("dst", dst);


    Mat dst;
    int flipCode[] = {1, 0, -1};

    for(int i = 0; i < 3; i++) {
        flip(src, dst, flipCode[i]); // 양수는 좌우대칭, 0이면 상하대칭, 음수면 둘 다 수행

        String desc = format("flipCode: %d", flipCode[i]);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }

    waitKey();
    destroyAllWindows();

    return 0;
}