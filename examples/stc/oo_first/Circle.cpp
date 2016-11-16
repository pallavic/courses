/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include <cmath>

#include "Circle.h"

const double Circle::pi = 3.14159265;

Circle::Circle(void) : r(0.0) {}

void Circle::set_radius(double radius)
{
   r = radius;
}

void Circle::set_area(double area)
{
   r = sqrt(area/pi);
}

double Circle::get_radius(void) const
{
   return r;
}

double Circle::get_area(void) const
{
   return r*r*pi;
}

