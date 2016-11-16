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

void Square::set_side(double side)
{
   s = side;
}

void Square::set_area(double area)
{
   s = sqrt(area);
}

double Square::get_side(void) const
{
   return s;
}

double Square::get_area(void) const
{
   return s*s;
}
