/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

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
