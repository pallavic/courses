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


#include<cstdlib>
#include<string>
#include<iostream>
#include<sstream>

#include "Library.h"

void get_input(int argc,char* argv[],std::string& id_from,double& length_from,std::string& id_to);

void initialize(void);

double calculate(const std::string& id_from,double length_from,const std::string& id_to);

int main(int argc,char* argv[])
{
   std::string id_from,id_to; // equal to "circle" or "square"
   double length_from;        // either radius or side value

   get_input(argc,argv,id_from,length_from,id_to);

   double lenght_to = Library::instance().get_equivalent_length(id_from,length_from,id_to);

   std::cout << "length is " << lenght_to << std::endl;
}

void get_input(int argc,char* argv[],std::string& id_from,double& length_from,std::string& id_to)
{
   if (argc==0) abort();

   const std::string program(!argv?"stc":argv[0]);

   if (argc<4) {std::cerr << "usage: " << program << " shape_from length_from shape_to" << std::endl; exit(-1);}

   id_from = std::string(argv[1]);
   std::istringstream ss(argv[2]); ss >> length_from;
   id_to = std::string(argv[3]);
}
