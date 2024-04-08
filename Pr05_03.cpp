#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("C:/Users/User/Desktop/suric.jpg");

    if (image.empty())
    {
        cout << "Error" << endl;
        return -1;
    }


    imshow("Original Image", image);
    waitKey(0);

    Mat split = image.clone();
    putText(split, "Width: " + to_string(image.cols) + ", Height: " + to_string(image.rows), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
    rectangle(split, Rect(500, 500, 100, 100), Scalar(0, 255, 255), 8);
    circle(split, Point(450, 100), 50, Scalar(0, 128, 128), 2);
    line(split, Point(10, 350), Point(550, 10), Scalar(192, 192, 192), 3);
    circle(split, Point(300, 300), 150, Scalar(255, 0, 255), -1);
    rectangle(split, Rect(120, 700, 100, 350), Scalar(0, 0, 128), -1);

    imshow("Annotated Image", split);
    waitKey(0);

    int centerX = image.cols / 2;
    int centerY = image.rows / 2;
    Mat one = image(Rect(0, 0, centerX, centerY));
    Mat two = image(Rect(centerX, 0, centerX, centerY));
    Mat three = image(Rect(0, centerY, centerX, centerY));
    Mat four = image(Rect(centerX, centerY, centerX, centerY));

    imshow("1", one);
    imshow("2", two);
    imshow("3", three);
    imshow("4", four);
    waitKey(0);


    Mat mask = Mat::zeros(image.size(), CV_8UC1);
    rectangle(mask, Rect(150, 50, 200, 200), Scalar(255), FILLED);
    Mat masked;
    image.copyTo(masked, mask);

    imshow("Masked Image", masked);
    waitKey(0);

    return 0;
}
