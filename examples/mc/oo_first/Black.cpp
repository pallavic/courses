/*****************************************************************************
 *                                                                           *
 * Copyright (C) 2012-2015 Andrea Pallavicini                                *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              *
 * GNU General Public License for more details.                              *
 *                                                                           *
 *****************************************************************************/


#include "Black.h"
#include "RandVarNormal.h"
#include<stdexcept>
#include<cmath>

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
