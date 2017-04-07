#ifndef OPENCV_COLOR_H
#define OPENCV_COLOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

extern void colordetect(char* img, int width, int height);
extern int gmax_area_xcentre;
extern int gmax_area_ycentre ; //global obstacle centre
extern double gmax_area; // global maximum area
//extern Rect grect;

#ifdef __cplusplus
}
#endif

#endif
