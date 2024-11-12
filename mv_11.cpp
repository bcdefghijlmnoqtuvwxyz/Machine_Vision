#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    VideoCapture cap("stopwatch.avi"); // 동영상 파일 객체 생성

    if(!cap.isOpened()) {
        cerr << "Video open failed!" << endl;
        return;
    }

    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl; // 전체 프레임 수 출력

    double fps = cap.get(CAP_PROP_FPS); // 비디오 파일의 초당 프레임 수 값을 받아옴
    cout << "FPS: " << fps << endl;

    int delay = cvRound(1000 / fps); // 각 프레임 사이의 시간 간격 delay(밀리초 단위) 계산

    Mat frame, inversed;

    while(true) {
        cap >> frame;

        if(frame.empty())
            break;

        inversed = ~frame;

        imshow("frame", frame);
        imshow("inversed", inversed);

        if(waitKey(delay) == 27)
            break;
    }

    destroyAllWindows();

    return 0;
}