/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include<cstdlib>
#include<string>
#include<iostream>
#include<sstream>

#include "ShapeFactory.h"
#include "Square.h"
#include "Circle.h"

void get_input(int argc,char* argv[],std::string& id_from,double& length_from,std::string& id_to);

void initialize(void);

double calculate(const std::string& id_from,double length_from,const std::string& id_to);

int main(int argc,char* argv[])
{
   std::string id_from,id_to; // equal to "circle" or "square"
   double length_from;        // either radius or side value

   get_input(argc,argv,id_from,length_from,id_to);

   initialize();

   double lenght_to = calculate(id_from,length_from,id_to);

   std::cout << "length is " << lenght_to << std::endl;
}

void initialize(void)
{
   ShapeFactory::instance().insert(new Square,"square");
   ShapeFactory::instance().insert(new Circle,"circle");
}

double calculate(const std::string& id_from,double length_from,const std::string& id_to)
{
   Shape* shape_from = ShapeFactory::instance().create(id_from);
   shape_from->set_length(length_from);
   Shape* shape_to = ShapeFactory::instance().create(id_to);
   shape_to->set_equal_area(*shape_from);
   return shape_to->get_length();
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
