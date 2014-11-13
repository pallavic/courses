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


#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
public:
   virtual Shape* clone(void) const=0;

   virtual double get_area(void) const =0;
   virtual void set_area(double area) =0;
   void set_equal_area(const Shape& shape)
   {
      set_area(shape.get_area());
   }

   virtual double get_length(void) const =0;
   virtual void set_length(double length) =0;
   void set_equal_legth(const Shape& shape)
   {
      set_length(shape.get_length());
   }
};

#endif
