/*****************************************************************************
 *                                                                           *
 * Copyright (C) 2012-2015 Andrea Pallavicini                                *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              *
 * GNU General Public License for more details.                              *
 *                                                                           *
 *****************************************************************************/


#include <cmath>

#include "Circle.h"

const double Circle::pi = 3.14159265;

Circle::Circle(void) : r(0.0) {}

void Circle::set_radius(double radius)
{
   r = radius;
}

void Circle::set_area(double area)
{
   r = sqrt(area/pi);
}

double Circle::get_radius(void) const
{
   return r;
}

double Circle::get_area(void) const
{
   return r*r*pi;
}

