#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    //
    Mat image = imread("gh.jpg");

    //
    //
    Mat hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);

    //
    Scalar lower_red(140, 200, 200);
    Scalar upper_red(180, 255, 255);

    Scalar lower_blue(101, 208, 206);
    Scalar upper_blue(140, 255, 255);

    //
    Mat red_mask, blue_mask;
    inRange(hsv, lower_red, upper_red, red_mask);
    inRange(hsv, lower_blue, upper_blue, blue_mask);

    //
    Mat combined = red_mask + blue_mask;

    //
    Mat m3 = getStructuringElement(0, Size(5, 5));
    dilate(combined, combined, m3);

    //
    Mat edges;
    Canny(combined, edges, 50, 150);

    //
    GaussianBlur(edges, edges, Size(3, 3), 0);

    //
    vector<vector<Point>> contours;
    findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    for (unsigned long i = 0; i < contours.size(); i++)
    {
        //
        RotatedRect ellipse = fitEllipse(contours[i]);

        //
        Point center = ellipse.center;
        cout << "Ellipse center:(" << center.x << "," << center.y << ")" << endl;
        int r = 20;
        circle(image, center, r, Scalar(0, 0, 225), 2);
    }

    //
    namedWindow("result", WINDOW_AUTOSIZE);
    imshow("result", image);

    waitKey(0);
    return 0;
}