/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:

  Circle(void);

  virtual Circle* clone(void) const;

  virtual double get_area(void) const;
  virtual void set_area(double area);
  virtual double get_length(void) const;
  virtual void set_length(double radius);

  double get_radius(void) const;
  void set_radius(double radius);

private:

  static const double pi;
  double r;
};

#endif
