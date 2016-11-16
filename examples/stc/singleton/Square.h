/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _SQUARE_H
#define _SQUARE_H

#include "Shape.h"

class Square : public Shape
{
public:

  Square(void);

  virtual Square* clone(void) const;

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
