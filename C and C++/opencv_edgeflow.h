#ifndef OPENCV_EDGE_H
#define OPENCV_EDGE_H

#ifdef __cplusplus
extern "C" {
#endif


float roe(char *img, char *prev_img, int width, int height);
//float roe(char *img, int width, int height, int flag);
extern int* F11;
#ifdef __cplusplus
}
#endif

#endif
