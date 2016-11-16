/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include<iostream>

#include"side_of_square.h"
#include"area_of_circle.h"

int main(void)
{
  const double radius = 1.0;
  double side,area;
  area = area_of_circle(radius);
  side = side_of_square(area);

  std::cout << "side is " << side << std::endl;
}
