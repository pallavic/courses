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
#include<iostream>

int main(void)
{
   const double S = 1.0;
   const double K = 1.0;
   const double vol = 0.2;
   const double T = 10;

   const unsigned long n = 100000;
   const unsigned long k = 10;

   double price = 0.0;
   double error = 0.0;
   mc_sim_call(S,K,vol,T,n,k,price,error);
      
   std::cout << "MC Simulation Price  = " << price << " +- " << error << std::endl;
}
