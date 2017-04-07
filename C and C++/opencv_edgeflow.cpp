#include "opencv_edgeflow.h"




#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "opencv_image_functions.h"
using namespace cv;
using namespace std;

int* find_hist(char img, int width, int height)
{
 // Create a new image, using the original bebop image.
  Mat M(width, height, CV_8UC2, img); // original
  Mat edge_image(width, height, CV_8UC1, Scalar(0));

  // convert RGB in paparazzi to GRAY in opencv
cvtColor(M, edge_image, CV_YUV2GRAY_Y422);


  /// Find edges

  int edgeThresh = 50;
  Canny(edge_image, edge_image, edgeThresh, edgeThresh * 3);

 //Normalization
    edge_image = edge_image/255;


  //sum of edge points in a column
  int sofeature = 0;

  //Histogram of columns
	int F1[width];

	for(int i=0; i< width; i++)
		{
		for(int j=0; j< height; j++)
		{
			//printf("getting pixel (%d, %d) of (%d, %d)\n", j, i, height, width);
			sofeature = sofeature + edge_image.at<uint8_t>(j,i);
			printf("getting pixel %d \n", sofeature);
		}
		F1[i] = sofeature;
		sofeature = 0;
		}
int* F1point = F1; 
return F1point;
}

int *F;//=new int[width];
int *F11;//=new int[width];

 float roe(char *img, char *prev_img, int width, int height)// float roe(char *img, int width, int height, int flag)
{
float A11 = 0.0;
float A12 = 0.0;
float A22 = 0.0;
float C1 = 0.0;
float C2 = 0.0;
//Mat M(width, height, CV_8UC2, img);

//Mat t2(width, height, CV_8UC1, Scalar(0));
//cvtColor(M, t2, CV_YUV2GRAY_Y422);
//grayscal_opencv_to_yuv422(t2, img);
//cvtColor(M, M, CV_RGB2GRAY);
//if(flag!=0)
//{
 F = find_hist(*prev_img, width, height);
//}

//else
//{
 F11 = find_hist(*img, width, height);
for (int k = 1; k<width;k++)
	{		
	int Ft = (F11[k] - F[k])*30; //30 is frame per second
	//Ft = np.asscalar(Ft)
 	int Fx = F11[k] - F11[k-1]; 
	//Fx = np.asscalar(Fx)	
	A11 = A11 + (Fx*Fx*k*k);
	A12 = A12 + (Fx*Fx*k);
	A22 = A22 + (Fx*Fx);
	C1 = C1 + (Fx*Ft*k);
	C2 = C2 + (Fx*Ft);
	}

//inverse
//float A[2][2] = {A22, -A12, -A12, A11};
int determinant = (A11*A22) - (A12*A12);
//double C[1][2] = {C1,C2};

//rate of expansion
float D = (A22*C1 -A12*C2)/determinant;
//double d = (-A12*C1 +A11*C2)/determinant;
float a = D+1;
F = F11;
return a; 
//} 
} 

 

  

