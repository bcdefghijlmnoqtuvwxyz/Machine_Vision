#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256)); // 256개의 빈으로 구성된 히스토그램 행렬인지 검사

    double histMax;
    minMaxLoc(hist, 0, &histMax); // hist 행렬 원소의 최댓값을 histMax 변수에 저장

    Mat imgHist(100, 256, CV_8UC1, Scalar(255)); // 256x100 크기의 새 영상 imghist 생성

    for(int i = 0, i < 256; i++) { // 각각의 빈에 대한 히스토그램 그래프를 그림
        line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
    }

    return imgHist;
}