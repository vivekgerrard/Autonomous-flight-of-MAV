/*
 * Copyright (C) 2015
 *
 * This file is part of Paparazzi.
 *
 * Paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * Paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file modules/computer_vision/colorfilter.c
 */

// Own header
#include "modules/computer_vision/colorfilter.h"
#include <stdio.h>
#include "modules/computer_vision/detect_edge.h"
#include "modules/computer_vision/opencv_edgeflow.h"
#include "modules/computer_vision/colordetection.h"
#include "modules/computer_vision/opencv_colordetection.h"
#include "modules/computer_vision/lib/vision/image.h"

struct video_listener *listener = NULL;


//char prev_buffer[240 * 520 * 2];
//struct image_t prev_img;

// Result
//int flag = 0;
//float expansion =0;
// Function
struct image_t *colorfilter_func(struct image_t *img);
struct image_t *colorfilter_func(struct image_t *img)
{

		
	//if(flag != 0)
	//	{
			//expansion = roe((char *) img->buf,(char *) prev_img.buf, img->w, img->h);//roe((char *) img->buf, img->w, img->h, flag);//
	//	}
	//else{
	//	flag = 1;
	//}
	colordetect((char *) img->buf, img->w, img->h);
	//printf("Copying image (%d, %d)\n", img->w, img->h);
	//image_copy(img, &prev_img);
	//memcpy(&prev_buffer, img->buf, 240 * 520 * 2 * sizeof(char));
	return img; // Colorfilter did not make a new image
}

void colorfilter_init(void)
{
  listener = cv_add_to_device(&COLORFILTER_CAMERA, colorfilter_func); //Video listening with function in cv.c
//image_create(&prev_img, 240, 520, IMAGE_YUV422);
}
