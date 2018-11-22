/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include "Black.h"
#include "RandVarNormal.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

Black::Black(double volatility,unsigned long nstate)
 : MCEngine(nstate)
{
   const double epsilon = 1.e-15;
   
   if (volatility<-epsilon) throw std::range_error("stock's volatility cannot be negative");

   this->volatility = std::max(0.0,volatility);
}

void Black::fill_path(const std::vector<double>& times,MCPath& path) const
{
   path.resize(times.size());

   RandVarNormal normrnd;
   const double halfvar = 0.5*volatility*volatility;

   double logS = 0.0; // all prices are re-scaled to stock's spot price

   std::vector<double>::const_iterator b=times.begin(), e=times.end();
   for (std::vector<double>::const_iterator p=b;p!=e;++p)
   {
      const double dt = p==b ? *p : *p-*(p-1);
      const double sdt = sqrt(dt);
      const double z = normrnd.draw();

      logS += -halfvar*dt + z*volatility*sdt;
      
      path[0] = std::exp(logS);
   }
}
