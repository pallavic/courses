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

#include "Square.h"

Square::Square(void) : s(0.0) {}

Square* Square::clone(void) const
{
   Square* square = new Square;
   square->set_side(s);
   return square;
}

double Square::get_area(void) const
{
   return s*s;
}

void Square::set_area(double area)
{
   s = sqrt(area);
}


double Square::get_length(void) const
{
   return get_side();
}

void Square::set_length(double length)
{
   set_side(length);
}

double Square::get_side(void) const
{
   return s;
}

void Square::set_side(double side)
{
   s = side;
}
