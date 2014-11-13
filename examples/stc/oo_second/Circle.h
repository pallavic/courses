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


#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:

  Circle(void);

  void set_radius(double radius);
  virtual void set_area(double area);
  double get_radius(void) const;
  virtual double get_area(void) const;

private:

  static const double pi;
  double a;
};

#endif
