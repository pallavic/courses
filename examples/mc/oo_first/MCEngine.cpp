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


#include "MCEngine.h"
#include "Payoff.h"
#include<cmath>
#include<stdexcept>

MCEngine::MCEngine(unsigned long nstate)
{
   if (nstate<2) throw std::range_error("at least two simulation paths are needed");

   this->nstate = nstate;
}

void MCEngine::init(const std::vector<double>& simultation_time)
{
   const double epsilon = 1.e-15;
   
   if (simultation_time.empty()) throw std::range_error("at least one simulation time is needed");
   
   times.reserve(simultation_time.size());
   std::vector<double>::const_iterator b=simultation_time.begin(),e=simultation_time.end();
   for (std::vector<double>::const_iterator p=b;p!=e;++p)
   {
      if (*p<-epsilon) throw std::range_error("simulation times cannot be negative");
      if (p>b && *p<*(p-1)+epsilon) throw std::range_error("simulation times must be increasing");
      times.push_back(std::max(0.0,*p));
   }
}
   
std::pair<double,double> MCEngine::price(const Payoff& payoff)
{
   MCPath path;
   double sample=0.0, samplesq=0.0;
   for (unsigned long i=0;i<nstate;++i)
   {
      fill_path(times,path);
      const double value = payoff.evaluate(path);
      sample += value;
      samplesq += value*value;
   }
   
   const double price = sample/(double)nstate;
   const double error = std::sqrt(std::max(samplesq/(double)nstate-price*price,0.0)/(nstate-1.0));

   return std::make_pair(price,error);
}
