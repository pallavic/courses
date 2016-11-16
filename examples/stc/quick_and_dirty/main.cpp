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

#include "Square.h"
#include "Circle.h"

void get_input(int argc,char* argv[],std::string& id,double& length);

int main(int argc,char* argv[])
{
  std::string id; // equal to "circle" or "square"
  double length;  // either radius or side value

  get_input(argc,argv,id,length);

  if (id=="square")
  {
    Square square; square.set_side(length);
    Circle circle; circle.set_equal_area(square);
    std::cout << "radius is " << circle.get_radius();
  }
  else if (id=="circle")
  {
    Circle circle; circle.set_radius(length);
    Square square; square.set_equal_area(circle);
    std::cout << "side is " << square.get_side();
  }
  else
  {
     std::cerr << "unknown shape " << id << " : enter 'circle' or 'square'" << std::endl;
     exit(-1);
  }

  std::cout << std::endl;
}

void get_input(int argc,char* argv[],std::string& id,double& length)
{
   if (argc==0) abort();

   const std::string program(!argv?"stc":argv[0]);

   if (argc<3) {std::cerr << "usage: " << program << " shape length" << std::endl; exit(-1);}

   id = std::string(argv[1]);
   std::istringstream ss(argv[2]); ss >> length;
}
