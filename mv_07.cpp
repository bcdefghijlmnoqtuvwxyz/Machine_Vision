#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

int main()
{
    float data[] = {1, 1, 2, 3};

    Mat mat1(2, 2, CV_32FC1, data);
    cout << "mat1:\n" << mat1 << endl; // [1, 1;
                                       //  2, 3]

    Mat mat2 = mat1.inv(); // 역행렬 
    cout << "mat2:\n" << mat2 << endl; // [3, -1;
                                       //  -2, 1]

    cout << "mat1.t():\n" << mat1.t() << endl; // [1, 2; 전치 행렬
                                               //  1, 3]

    cout << "mat1 + 3:\n" << mat1 + 3 << endl; // [4, 4;
                                               //  5, 6]

    cout << "mat1 + mat2:\n" << mat1 + mat2 < endl; // [4, 0;
                                                    //  0, 4]
                                                    
    cout << "mat1 * mat2:\n" << mat1 * mat2 << endl; // [1, 0;
                                                     //  0, 1]

    return 0;
}