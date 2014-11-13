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


#ifndef _SQUARE_H
#define _SQUARE_H

#include "Shape.h"

class Square : public Shape
{
public:

  Square(void);

  virtual double get_area(void) const;
  virtual void set_area(double area);
  virtual double get_length(void) const;
  virtual void set_length(double length);

  double get_side(void) const;
  void set_side(double side);

private:  

  double s;
};

#endif
