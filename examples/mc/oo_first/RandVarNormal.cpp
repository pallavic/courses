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
