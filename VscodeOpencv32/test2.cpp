#include <opencv2/highgui/highgui.hpp>//OpenCV highgui 模块头文件 ~
#include <opencv2/imgproc/imgproc.hpp>//OpenCV 图像处理头文件 
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <ctype.h>
 
using namespace cv;
using namespace std;


using namespace cv; // 包含 cv 命名空间
int main() //控制台应用程序的入 口 函数，我们的程序从这里开始
{
Mat srclmage = imread("learn.jpg"); 
imshow("原图",srclmage);
//进行腐蚀操作 
Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));//getStructuringElement函数的返回值为指定形状和尺寸的结构元素(内核矩阵〉
Mat dstlmage;
erode(srclmage, dstlmage, element);
//显示效果图 
imshow ("效果图", dstlmage); 
	waitKey(0);
	return 0;
}