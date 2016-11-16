/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
public:
  virtual void set_area(double area) =0;
  virtual double get_area(void) const =0;

  void set_equal_area(const Shape& shape)
  {
    set_area(shape.get_area());
  }
};

#endif
