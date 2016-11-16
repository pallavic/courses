/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include <cstdlib>
#include <iostream>

#include "ShapeFactory.h"

ShapeFactory::ShapeFactory(void) {}

ShapeFactory::~ShapeFactory(void)
{
   for (std::vector<Shape*>::iterator p=garbage.begin(),e=garbage.end();p!=e;++p)
      delete *p;
}

void ShapeFactory::insert(Shape* shape,const std::string& id)
{
   if (!shape) 
   {
      std::cerr << "invalid shape " << id << std::endl;
      exit(-1);
   }

   store[id] = shape;
}

Shape* ShapeFactory::create(const std::string& id) const
{
   std::map<std::string,Shape*>::const_iterator p = store.find(id);
   if (p==store.end())
   {
      std::cerr << "unkown shape " << id << std::endl;
      exit(-1);
   }

   return p->second->clone();
}
