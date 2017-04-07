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
 * @file "modules/computer_vision/colordetection.h"
 * @author Ajith
 * detects largest black and orange
 */

#ifndef COLORDETECTION_H
#define COLORDETECTION_H
#include <stdint.h>
#include "modules/computer_vision/cv.h"


extern void color_detect_init(void);
extern struct video_listener *color_listener;

#endif

