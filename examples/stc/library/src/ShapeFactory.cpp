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


#include <cstdlib>
#include <iostream>

#include "ShapeFactory.h"

ShapeFactory* ShapeFactory::factory = 0;

ShapeFactory::ShapeFactory(void) {}

ShapeFactory::~ShapeFactory(void)
{
   for (std::vector<Shape*>::iterator p=garbage.begin(),e=garbage.end();p!=e;++p)
      delete *p;
}

ShapeFactory& ShapeFactory::instance(void)
{
   if (!factory) factory = new ShapeFactory;
   return *factory;
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
