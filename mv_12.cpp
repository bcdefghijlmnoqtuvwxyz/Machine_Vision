#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return;
    }

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    douvlee fps - cap.get(CAP_PROP_FPS);

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    // DivX MPEG-4 코덱에 해당하는 fourcc 코드 생성

    int delay = cvRound(1000 / fps);

    VideoWriter outputVideo("output.avi", fourcc, fps, Size(w. h));
    // 저장할 동영상 파일을 생성, 동영상 파일 이름은 output.avi

    if(!outputVideo.isOpened()) {
        cout << "File open failed!" << endl;
        return;
    }

    Mat frame, inversed;

    while(true) {
        cap >> frame;
        if(frame.empty())
        break;

        inversed = ~frame;
        outputVideo << inversed;

        imshow("frame", frame);
        inshow("invesed", inversed);

        if(whitKey(delay) == 27)
            break;
    }

    destroyAllWindows();

    return 0;
}