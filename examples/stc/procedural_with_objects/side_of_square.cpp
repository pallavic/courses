/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include <math.h>

#include "side_of_square.h"

double side_of_square(double area)
{
  double side;
  side = sqrt(area);
  return side;
}
