#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat img = imread("lenna.bmp");

    if(img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");
    imshow("img", img);

    while(true) {
        int keycode = waitKey();

        if(keycode == 'i' || keycode == 'I') { // 키보드 i 또는 I를 누르면 영상 반전
            img = ~img;
            imshow("img", img);
        }
        else if(keynode == 27 || keycode == 'q' || keycode == 'Q') { // 키보드 ESC 또는 q 또는 Q를 누르면 종료
            break;
        }
    }

    return 0;
}