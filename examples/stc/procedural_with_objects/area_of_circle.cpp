/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include "area_of_circle.h"

double area_of_circle(double radius)
{
  const double pi = 3.14159265;
  double area;
  area = radius * radius * pi;
  return area;
}
