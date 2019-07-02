#include <opencv2/opencv.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void help(char ** argv){
    cout << endl << "My New Example" << endl << argv[0]
 <<" [path/image]"<<endl
<< "\nor, read from camera: \n" <<argv[0]
 <<"\nFor example: \n"<<argv[0]<<"../tree.avi\n"<<endl;
}

int main (int argc, char **argv){

help(argv);
cv::namedWindow("My Example", cv::WINDOW_AUTOSIZE);
cv::VideoCapture cap;

if(argc==1){
cap.open(0);
} else {
cap.open(argv[1]);
}

if(!cap.isOpened()){
cerr<<"Couldn't open capture."<<endl;
return -1;
}

cv::Mat frame;
cv::Point pt1(50,50), pt2(100,100);
int x = 50;
int y = 50;
int pol = 1;
for(;;){
cap >> frame;
if(frame.empty()){
break;
}

pol++;

x = (x * y + pol * x + rand()%50)%400;
y = (y + pol * y + rand() %50)%300;

pt1.x = x;
pt1.y = y;
pt2.x = x + 50;
pt2.y = y + 50;
cv::rectangle(frame, pt1, pt2, cv::Scalar::all(0));

cv::imshow("My Example", frame);

if((char) cv::waitKey(33) >=0){
break;
}
}
return 0;
}