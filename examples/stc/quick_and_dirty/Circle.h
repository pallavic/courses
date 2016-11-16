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

  void set_radius(double radius);
  virtual void set_area(double area);
  double get_radius(void) const;
  virtual double get_area(void) const;

private:

  static const double pi;
  double r;
};

#endif
