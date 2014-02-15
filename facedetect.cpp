#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
using namespace cv;
void detectAndDraw( Mat& img, CascadeClassifier& cascade);	//detect faces
string cascadeName = "./haarcascade_frontalface_alt2.xml";	//location of the cascade (filter chain file)

int main( int argc, char** argv )
{
   CascadeClassifier cascade(cascadeName);	//cascade object
   Mat frame, frameCopy, image;
   frame =imread("/home/omsi/1.jpg", CV_LOAD_IMAGE_UNCHANGED); 
   if( frame.empty() )			//empty? something is wrong
	{cout<<"frame is empty"<<endl; return 0;}
   detectAndDraw( frame, cascade);
return 0;
}

void detectAndDraw( Mat& img, CascadeClassifier& cascade)
{
    int i = 0;
    double t = 0;
    vector<Rect> faces;
    Mat face;
    Mat gray, smallImg( cvRound (img.rows), cvRound(img.cols), CV_8UC1 );	//smallimg to be passed to cascade
   
    cvtColor( img, gray, CV_BGR2GRAY );		//grayscale to speedup
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );	
    equalizeHist( smallImg, smallImg );

    t = (double)cvGetTickCount();		//find detection time
    cascade.detectMultiScale( smallImg, faces,		//do not change it, it may not work
        1.1, 2, 0					//look for faces
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        //|CV_HAAR_DO_ROUGH_SEARCH
        |CV_HAAR_SCALE_IMAGE
        ,
        Size(30, 30) );
    t = (double)cvGetTickCount() - t;
    printf( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );
    for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )	//go through the faces
    {
     Rect roi(r->x, r->y,r->width, r->height);
     face=img(roi);
     cvtColor( face, face, CV_BGR2GRAY );		//grayscale to speedup
     resize(face, face, Size(200, 200), 0, 0, INTER_CUBIC);
     normalize(face, face, 0, 255, NORM_MINMAX, CV_8UC1);
     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
     imshow("MyWindow", face); //display the image which is stored in the 'img' in the "MyWindow" window
     waitKey(0); //wait infinite time for a keypress
     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
     imwrite( "/home/omsi/out.jpg", face);
    }    
}
