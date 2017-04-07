 /*
 * Copyright (C) Ajith
 *
 * This file is part of paparazzi
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file "modules/computer_vision/colordetection.c"
 * @author Ajith
 * detects largest black and orange
 */

#include "modules/computer_vision/cv.h"
#include "modules/computer_vision/colordetection.h"
#include "modules/computer_vision/opencv_colordetection.h"
#include <stdio.h>
#include "modules/computer_vision/lib/vision/image.h"
//#include "opencv_image_functions.h"

#include <string.h>
struct video_listener *color_listener = NULL;//*color_listener = NULL;
//void colordetection_func(struct image_t *img);
//struct image_t *colordetection_func(struct image_t *img);
//struct image_t *colordetection_func(struct image_t *img)
void colordetection_func(struct image_t *img1);
void colordetection_func(struct image_t *img1)
{

//colordetect((char *) img->buf, img->w, img->h);
//return img;

}



 void color_detect_init()
 {
 color_listener = cv_add_to_device(&COLORDETECTION_CAMERA, colordetection_func); 
}



