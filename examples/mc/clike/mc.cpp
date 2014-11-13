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


#include "mc.h"
#include "normrnd.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

void mc_sim_call(double S,double K,double vol,double T,unsigned long n,unsigned long k,double& price,double& error)
{
   const double epsilon = 1.e-14;
   
   if (S<epsilon) throw std::range_error("stock's price must be positive");
   if (K<epsilon) throw std::range_error("option's strike must be positive");

   if (vol<-epsilon) throw std::range_error("stock's volatility cannot be negative");
   vol = std::max(0.0,vol);

   if (T<-epsilon) throw std::range_error("option's maturity cannot be negative");
   T = std::max(0.0,T);

   if (n<2) throw std::range_error("at least two simulations path are needed");
   if (k<1) throw std::range_error("at least one simulation time is needed");
   
   const double dt = T/(double)k;
   const double sdt = std::sqrt(dt);

   double sample = 0.0;
   double samplesq = 0.0;
   
   for (unsigned long state=0;state<n;++state)
   {
      double logS = 0.0;
      
      for (unsigned long time=0;time<k;++time)
      {
         const double z = normrnd();
         
         logS += -0.5*vol*vol*dt + z*vol*sdt;
      }

      const double payoff = std::max(std::exp(logS)-K,0.0);

      sample += payoff;
      samplesq += payoff*payoff;
   }
   
   price = sample/(double)n;
   error = std::sqrt(std::max(samplesq/(double)n-price*price,0.0)/(n-1.0));
}
