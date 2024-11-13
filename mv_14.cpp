#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));

    putText(img, "FONT_HERSHEY_SIMPLEX", Piont(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));

    imshow("img", img);

    waitKey(0);

    return 0;
}