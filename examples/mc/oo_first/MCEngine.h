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


#ifndef _MCENGINE_H
#define _MCENGINE_H

#include "MCPath.h"
#include<utility>
#include<vector>

class Payoff;

class MCEngine
{
public:

   MCEngine(unsigned long nstate=1000);
   virtual ~MCEngine(void) {}
   
   void init(const std::vector<double>& simultation_time);

   std::pair<double,double> price(const Payoff& payoff);

   virtual void fill_path(const std::vector<double>& times,MCPath& path) const =0;

private:

   unsigned long nstate;
   std::vector<double> times;
};

#endif
