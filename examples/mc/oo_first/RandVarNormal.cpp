/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include "RandVarNormal.h"
#include <stdexcept>
#include <cstdlib>
#include <cmath>

const double RandVarNormal::pi = 4.0 * std::atan(1.0);

RandVarNormal::RandVarNormal(double m,double s)
{
   const double epsilon = 1.e-15;

   this->m = m;   

   if (s<-epsilon) throw std::range_error("normal variable's standard deviation cannot be negative");
   this->s = std::max(0.0,s);   
}

double RandVarNormal::draw(void)
{
   const double theta = 2.0*pi*((rand()+1.0)/(RAND_MAX+1.0));
   const double rsq = -2.0*log((rand()+1.0)/(RAND_MAX+1.0));  
   const double z = std::sqrt(rsq)*std::cos(theta);
   return m + z*s;
}
