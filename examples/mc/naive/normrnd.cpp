/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include "normrnd.h"
#include <algorithm>
#include <cmath>

const double pi = 3.1415926535897932;

double normrnd(double m,double s)
{
   const double theta = 2.0*pi*((rand()+1.0)/(RAND_MAX+1.0));
   const double rsq = -2.0*log((rand()+1.0)/(RAND_MAX+1.0));
   const double z = std::sqrt(rsq)*std::cos(theta);
   return m + z*s;
}
