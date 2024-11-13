#include "opencv2/opencv.hpp" 
#include <iostream> 

using namespace cv; 
using namespace std; 

// String filename = "mydata.yml";
// String filename = "mydata.yml";
String filename = "mydata.json"; // readData() 함수를 사용하기 위해 데이터 파일 이름을 전역 변수로 선언

int main()
{ 
    /* 파일에 데이터 저장 */
    String name = "Jane";
    int age = 10;
    Point pt1(100, 200);
    vector<int> scores = {80, 90, 50};
    Mat mat1 = (mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

    FileStorage fs(filename, FileStorage::WRITE); // FileStorage 객체를 쓰기 모드로 생성

    if(!fs.isOpened()) {
        cerr << "File open failed!" << endl;
        return;
    }

    fs << "name" << name; // << 연산자를 이용하여 준비한 데이터를 파일에 저장
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "scores" << scores;
    fs << "data" << mat1;

    fs.release(); // 데이터 저장이 끝나면 파일 닫음


    /* 파일에 데이터 호출 */
    String name;
    int age;
    Point pt1;
    vector<int> scores;
    Mat mat1;

    FileStorage fs(filename, FileStorage::REDA); // FileStorage 객체를 읽기 모드로 생성

    if(!fs.isOpened()) {
        cerr << "File open failed!" << endl;
        return;
    }

    fs["name"] >> name; // [], >> 연산자를 이용하여 데이터를 읽음
    fs["age"] >> age;
    fs["point"] >> pt1;
    fs["scores"] >> scores;
    fs["data"] >> mat1;

    fs.release(); // 데이터 저장이 끝나면 파일 닫음

    cout << "name: " << name << endl; // 데이터 제대로 읽었는지 확인
    cout << "age: " << age << endl;
    cout << "point: " << point << endl;
    cout << "scores: " << Mat(scores).t() << endl;
    cout << "data:\n" << mat1 << endl;

    return 0;
}