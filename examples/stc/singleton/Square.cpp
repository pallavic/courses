/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

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
