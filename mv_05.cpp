#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std;

int main()
{
    Mat mat1 = Mat::zeros(3, 4, CV_8UC1); // 3x4 uchar 자료형의 모든 원소가 0인 행렬 선언

    for (int j = 0; j < mat1.rows; j++) { // 얕은 복사, 행, 3
        for (int i = 0; i < mat1.cols; i++) { // 얕은 복사, 열, 4
            mat1.at<uchar>(j, i)++; // 가장 직관적인 행렬 원소 접근 방법, 반환값을 변경하면 그대로 변경됨
                                    // 임의 좌표 원소에 빈번하게 접근할 경우 사용
        }
    }

    for (int j = 0; j < mat1.rows; j++) {
        uchar* p = mat1.ptr<uchar>(j); // 주소 반환 포인터, for 반복문에서는 이 방법이 더 빠르게 동작
        for(int i = 0; i < mat1.cols; i++) {
            p[i]++;
        }
    }

    // Iterator은 반복자라는 뜻으로 앞서 했던 at, ptr은 행렬의 크기를 벗어나면 에러가 발생
    // 행렬 크기에 상관없이 행렬 전체 원소를 차례대로 참조
    // begin() 함수로 행렬의 첫 번쨰 원소 위치를 얻음, end() 함수로 마지막 원소 바로 다음 위치를 얻음
    // 동작속도는 ptr() 함수보다 느리고 at 함수()처럼 임의의 위치에 자유로운 접근이 어려워 사용성이 높지 않음

    for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) { // end와 위치가 같으질 때까지 위치를 증가시킴
        (*it)++; // 원소 값을 참조, 해당 위치 원소 값을 1씩 증가시킴
    }

    cout << "mat1:\n" << mat1 << endl;

    return 0;
}