#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main() 
{
    VideoCapture cap(0); // VideoCapture 객체 생성 및 컴퓨터에 연결된 기본 카메라 사용 설정

    if (!cap.isOpened()) { // 카메라 장치가 열리지 않았다면 에러 메시지 출력 및 함수 종료
        cerr << "Camera open failed!" << endl;
        return;
    }

    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl; // 가로 크기 출력
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl; // 세로 크기 출력

    Mat frame, inversed;

    while(true) {
        cap >> frame; // 한 프레임을 받아옴 

        if(frame.empty()) // 프레임 영상이 비어 있으면 빠져나옴
            break;

        inversed = ~frame; // 프레임 반전

        imshow("frame", frame);
        imshow("inversed", inversed);

        if(waitKey(10) == 27) // 사용자로부터 10ms 시간 동안 키보드 입력 대기, 키보드 입력이 있고 해당 키 값인 27(ESC key)면 빠져나옴
            break;
    }

    destroyAllwindows(); // 모든 창을 닫음

    return 0;
} // 함수가 종료될 때 cap 변수가 소멸되며 자동으로 카메라 장치를 닫아서 cap.release() 함수 호출 생략