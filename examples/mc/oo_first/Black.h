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


#ifndef _BLACK_H
#define _BLACK_H

#include "MCEngine.h"

class Black : public MCEngine
{
public:

   Black(double volatility,unsigned long nstate=1000);
   virtual ~Black(void) {}
   
   virtual void fill_path(const std::vector<double>& times,MCPath& path) const;

private:

   double volatility;
};

#endif
