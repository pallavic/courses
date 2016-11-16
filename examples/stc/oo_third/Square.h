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

  void set_side(double side);
  virtual void set_area(double area);
  double get_side(void) const;
  virtual double get_area(void) const;

private:  

  double s;
};

#endif
