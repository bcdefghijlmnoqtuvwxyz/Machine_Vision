#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

    putText(img, "FONT_HERSHEY_SIMPLEX", Piont(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));

    const String text = "Hello, OpenCV"; // 문자열
    int fontFace = FONT_HERSHEY_TRIPLEX; // 폰트 종류
    double fontScale = 2.0; // 비율
    int thickness = 1; // 선 두께

    Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
    Size sizeImg = img.size();

    Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2); 
    // sizeText와 sizeImg 크기 정보를 이용하여 출력할 좌표 계산
    
    putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness); // 문자열 출력
    rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1); // 문자열을 감싸는 사각형 영역

    imshow("img", img);

    waitKey(0);

    destroyAllWindows();

    return 0;
}