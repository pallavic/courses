/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include<iostream>

#include"stc.h"

int main(void)
{
  const double radius = 1.0;
  double side;

  side = squaring_the_circle(radius);

  std::cout << "side is " << side << std::endl;
}
