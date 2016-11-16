/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include "mc.h"
#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>

void get_input(int argc,char* argv[],double& K,double& vol,double& T,unsigned long& n,unsigned long& k);

int main(int argc,char* argv[])
{
   const std::string program(!argv?"mc":argv[0]); // program name used for error messages

   const double S = 1.0; // prices are re-scaled to stock's spot price 

   double K, vol, T;
   unsigned long n, k;

   try
   {
      get_input(argc,argv,K,vol,T,n,k);
   }
   catch (...)
   {
      std::cerr << "usage: " << program << " strike volatility maturity nstate ntime" << std::endl; std::exit(-1);
   }

   double price = 0.0, error = 0.0;
   try
   {   
      mc_sim_call(S,K,vol,T,n,k,price,error);
   }
   catch (std::exception& e)
   {
      std::cerr << "error: " << program << " exception caught : " << e.what() << std::endl; std::exit(-1);
   }
   catch (...)
   {
      std::cerr << "error: " << program << " unknown exception" << std::endl; std::exit(-1);
   }
      
   std::cout << "MC Simulation Price  = " << price << " +- " << error << std::endl;
}

void get_input(int argc,char* argv[],double& K,double& vol,double& T,unsigned long& n,unsigned long& k)
{
   if (argc<6) throw 0;

   {std::istringstream ss(argv[1]); ss >> K;}
   {std::istringstream ss(argv[2]); ss >> vol;}
   {std::istringstream ss(argv[3]); ss >> T;}
   {std::istringstream ss(argv[4]); ss >> n;}
   {std::istringstream ss(argv[5]); ss >> k;}
}
