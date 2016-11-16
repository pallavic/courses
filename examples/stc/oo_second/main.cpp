/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include<iostream>

#include "Square.h"
#include "Circle.h"

int main(void)
{
  const double radius = 1.0;

  Circle circle; circle.set_radius(radius);
  Square square; square.set_area(circle.get_area());

  std::cout << "side is " << square.get_side()
            << std::endl;
}
