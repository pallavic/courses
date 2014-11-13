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
