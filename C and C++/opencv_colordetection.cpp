#include "opencv_colordetection.h"


#include "opencv_image_functions.h"
using namespace std;
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
using namespace cv;


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int gmax_area_xcentre;
int gmax_area_ycentre ; //global obstacle centre
double gmax_area; // global maximum area
Rect grect;			// global maximum rectangle
vector<vector<Point> > gcontour;		// global maximum contour


void colordetect(char* img, int width, int height)
{


gmax_area_xcentre = 0, gmax_area_ycentre = 0; //global obstacle centre
gmax_area = 0; // global maximum area


   // Create a new image, using the original bebop image.
  Mat M(width, height, CV_8UC2, img); // original
  Mat frame;//, im, t1, t2;

  // convert YUV_Y422 in paparazzi to BGR in opencv
//cvtColor(M, M, CV_YUV2BGR_Y422);   //YUV_Y422 is the format ouputted from the video_stream.
cvtColor(M, frame, CV_YUV2BGR_Y422);
//cvtColor(frame, frame, CV_BGR2YUV);


//flip(frame,frame,1);
Size size(width, height);


Mat im(width, height, CV_8UC3, Scalar(0,0,0));
Mat t1(width, height, CV_8UC1, Scalar(0));
Mat t2(width, height, CV_8UC1, Scalar(0));

cvtColor(frame,im,CV_BGR2HSV);
int Hl[2] = {0,0}, Sl[2] = {200,0}, Vl[2] = {50,0}; // orange & black  [5, 50, 50], [15, 255, 255]    

int Hh[2] = {15,200}, Sh[2] = {255,255}, Vh[2] = {150,20};

 for(int j=0; j<=1;j++)	// run for j colors
	{
		inRange(im, Scalar(Hl[j],Sl[j],Vl[j]), Scalar(Hh[j],Sh[j],Vh[j]), t1);
		threshold(t1,t1,127,255, THRESH_TOZERO);
		GaussianBlur(t1,t1,Size(3,3), 0, 0);
	        dilate(t1, t1, Mat(),Point(-1,-1),3);
		erode(t1,t1,Mat(),Point(-1,-1),3) ;  //Tune for erode and dilate required
		t2 = t1.clone();

		

		vector<vector<Point> > contour;
		vector<Vec4i> hierarchy;
		findContours(t1,contour,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_NONE);

		double max_area=0;
		int max_area_i = 0, i = 0;
		Rect rect1, rect2;
		vector<vector<Point> > it;
		it = contour;
		for( int i = 0; i< it.size(); i++ )	// find blob with maximum area of this color
			 {
				double a = contourArea(it[i]);
		         	if (a > max_area)
		  		      {
		  		          max_area = a;
		  		          max_area_i = i;
		  		      }
		  		      // Rectangle around all blobs of this color
		  		      rect1 = boundingRect(it[i]);
		  		      rectangle(t2,Point(rect1.x,rect1.y),Point(rect1.x+rect1.width,rect1.y+rect1.height),Scalar(255),2);
		         }
		  		  //imshow("My Window2",t2);

		  		  it = contour;	  
		  		  int max_area_xcentre, max_area_ycentre;
		  		  for( int i = 0; i< it.size(); i++ )
		  		  {
		  			  if(i==max_area_i)
		  			  {
		  				  rect2 = boundingRect(it[i]);
		  				  Moments moment=moments(it[i],0);
		  				  if (moment.m00 != 0.000)
		  				  {
		  					  max_area_xcentre = int(moment.m10/moment.m00);
		  					  max_area_ycentre = int(moment.m01/moment.m00);
		  				  }

		  				  if(max_area > gmax_area) // if this color has larger blob set to global
		  				  {
		  					gmax_area_xcentre = max_area_xcentre;
		  					gmax_area_ycentre = max_area_ycentre;
		  					grect = rect2;
		  					gmax_area = max_area;
		  					gcontour = it;
		  				  }

		  			  }
		  		  }

	}
		  	  // Plot global results

		  	  rectangle(M ,Point(grect.x,grect.y),Point(grect.x+grect.width,grect.y+grect.height),Scalar(0,255,0),2,8);
		  	  drawContours(frame,gcontour,-1,Scalar(0,0,255),1,8); 
		  	  circle(frame,Point(gmax_area_xcentre,gmax_area_ycentre),3,Scalar(0,0,255),-1);
			if(gmax_area!=0.00)
			{
			  printf("Area : %f ", gmax_area);
			}		

 			
			//colorrgb_opencv_to_yuv422(M, img);
			  //dest = frame;
		  	  //imshow("My Window1",frame);
		  	  //waitKey(10000);

	
}





