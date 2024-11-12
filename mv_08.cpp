#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE); // 그레이스케일 영상으로 불러옴

    Mat img1f;
    img1.converTo(img1f, CV_32FC1); // 실수형으로 변경
    // converTo() 함수는 행렬 원소의 타입을 다른 타입으로 변경, 모든 원소에 일정한 값을 더하거나 곱할 수 있음
    // uchar 자료형을 주로 쓰지만, 연산의 정확도를 높이기 위해 float, double 같은 실수형으로 변환하기도 함
    // 0부터 1 사이의 실수 값으로 구성된 2차원 행렬을 영상 형태로 화면에 나타내고 싶을 때,
    // 행렬의 모든 원소에 255를 곱한 후 uchar 자료형으로 변환하여 그레이스케일 영상 형식으로 만든 후 imshow() 함수를 사용하여 화면에 출력

    uchar data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Mat mat1(3, 4, CV_8UC1, data1); // 3x4 행렬로 변환
    Mat mat2 = mat1.reshape(0, 1); // 1x12 행렬로 변환

    cout << "mat1:\n" << mat1 << endl;
    cout << "mat2:\n" << mat2 << endl;

    Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255; // 원소 1로 채워진 1x4 행렬에 255를 곱한 값
    mat1.push_back(mat3); // mat1 3x4 행렬의 마지막 행에 mat3 1x4 행렬 추가
                          // pop_back() 함수로 맨 아래 행을 제거할 수 있음
    cout << "mat1:\n" << mat1 << endl;

    mat1.resize(6, 100); // 3x4 행렬을 6x4의 행렬로 변경, 추가된 원소는 모두 100으로 설정됨
    cout << "mat1:\n" << mat1 << endl;

    return 0;
}