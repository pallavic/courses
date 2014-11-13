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


#ifndef _RANDVAR_NORMAL_H
#define _RANDVAR_NORMAL_H

#include "RandVar.h"

class RandVarNormal : public RandVar
{
public:
   
   RandVarNormal(double m=0.0,double s=1.0);
   virtual ~RandVarNormal(void) {}
   
   virtual double draw(void);
   
private:
   
   static const double pi;
   
   double m, s;
};

#endif
