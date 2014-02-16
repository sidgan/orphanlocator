#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "cv.hpp"
//-
#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;

//-
//#define LBPH_RADIUS    3
//#define LBPH_NEIGHBORS 8
//#define LBPH_GRID_X    8
//#define LBPH_GRID_Y    8
//#define LBPH_THRESHOLD 250.0

#define LBPH_RADIUS    3
#define LBPH_NEIGHBORS 4
#define LBPH_GRID_X    6
#define LBPH_GRID_Y    6
#define LBPH_THRESHOLD 250.0
//-


class FaceDetector{
private:
	CascadeClassifier cascade[4];
public:
	void Load(){
		cascade[0].load("/var/www/FaceRecognition/haarcascade_frontalface_default.xml");
		cascade[1].load("/var/www/FaceRecognition/haarcascade_frontalface_alt.xml");
		cascade[2].load("/var/www/FaceRecognition/haarcascade_frontalface_alt2.xml");
		cascade[3].load("/var/www/FaceRecognition/haarcascade_frontalface_alt_tree.xml");
	}
	Mat FaceDetect( Mat& img,bool Colored,bool &HasRes){
		vector<Rect> faces;
		Mat face;
		Mat gray, smallImg( cvRound (img.rows), cvRound(img.cols), CV_8UC1 );	//smallimg to be passed to cascade
		int i;
		cvtColor( img, gray, CV_BGR2GRAY );		//grayscale to speedup
		resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );	
		equalizeHist( smallImg, smallImg );
		for (int i =0 ; i < 4 ;i++){
			faces.clear();
		cascade[i].detectMultiScale( smallImg, faces,		//do not change it, it may not work
		    1.1, 2, 0					//look for faces
		    |CV_HAAR_FIND_BIGGEST_OBJECT
		    //|CV_HAAR_DO_ROUGH_SEARCH
		    |CV_HAAR_SCALE_IMAGE
		    ,
		    Size(30, 30) );
		if (faces.size() >0) {break;}
		}
		//returns the first facefound 
		for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )	//go through the faces
		{
			Rect roi(r->x, r->y,r->width, r->height);
			face=img(roi);
			
		//imwrite("C:/Users/Hosam/Documents/Visual Studio 2012/Projects/ConsoleApplicationweqwe/x64/Release/Cas/x1.jpg",face);
			if (!Colored)cvtColor( face, face, CV_BGR2GRAY );		//grayscale to speedup
			resize(face, face, Size(200, 200), 0, 0, INTER_CUBIC);
			normalize(face, face, 0, 255, NORM_MINMAX, CV_8UC1);
		//imwrite("C:/Users/Hosam/Documents/Visual Studio 2012/Projects/ConsoleApplicationweqwe/x64/Release/Cas/x2.jpg",face);	
			//namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
			//imshow("MyWindow", face); //display the image which is stored in the 'img' in the "MyWindow" window
			//waitKey(0); //wait infinite time for a keypress
			//destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
			HasRes = true;
			return face;
		}    
		HasRes = false;
		return Mat() ;
	}
};


class PersonRecognizer{
private:
	Ptr<FaceRecognizer> _model;
public:
double recognize( Mat &face_out, Mat &face_database )  {
     vector<int> labels;
	 vector<Mat> imgs;
	 double confidence =0;
	 imgs.push_back(face_database);
	 labels.push_back(0);
   // for (vector<int>::iterator it = labels.begin() ; it != labels.end() ; *(it++) = PERSON_LABEL);
   // _faceSize = Size(imgs[0].size().width, imgs[0].size().height);
    
    //build recognizer model:
	_model = createLBPHFaceRecognizer(LBPH_RADIUS, LBPH_NEIGHBORS, LBPH_GRID_X,LBPH_GRID_Y, LBPH_THRESHOLD);
    _model->train(imgs, labels);
	
	// Mat gray;
    int label;
    //cvtColor(face, gray, CV_BGR2GRAY);
	//resize(face_out, face_out);
    _model->predict(face_out, label, confidence);
	return confidence;
}
};


void writeval(double val){


	cout << val << endl;

	 ofstream myfile;
	 myfile.open("res.txt");
	 myfile.trunc;
	 myfile <<val;
	 myfile.close();
}


int main( int argc, const char** argv )
{

	 

	double res =0;
	try{
	 bool res1 = false,res2= false; 
	 Mat image1;
	 image1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file
	
	 Mat image2;
	 image2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);   // Read the file
	 
	 FaceDetector fc1;
	 FaceDetector fc2;
	 fc1.Load();
	 fc2.Load();
	 Mat Face1;
	 Mat Face2;

	 Face1 = fc1.FaceDetect(image1,false, res1);
	 Face2 = fc2.FaceDetect(image2,false, res2);
	
	 if (!res1 || !res2) {
		 writeval(-1);
		 return 0;
	 }
	 PersonRecognizer pr;
	 double val1 = pr.recognize(Face1,Face2);
	 double val2 = pr.recognize(Face2,Face1);
	
	 double res1x = (LBPH_THRESHOLD - val1 )  * (double)(1.0/(double) LBPH_THRESHOLD);
	 double res2x = (LBPH_THRESHOLD - val2 )  * (double)(1.0/(double) LBPH_THRESHOLD);
	 
	 

	 if (res1x > LBPH_THRESHOLD || res1x < 0) res1x = -1;
	 if (res2x > LBPH_THRESHOLD || res2x < 0) res2x = -1;
	 res = max(res1x,res2x);

	 writeval(res );
	 return 0;
	}catch(exception e){
		 writeval(-1);
	}
return 0;
 
}
