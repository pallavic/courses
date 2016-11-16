/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include<iostream>

int main(void)
{
  const double square_root_of_pi = 1.77245385;
  const double radius = 1.0;
  double side;
  
  side = radius * square_root_of_pi;
  
  std::cout << "side is " << side << std::endl;
}

