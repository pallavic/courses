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


#ifndef _SHAPE_FACTORY_H
#define _SHAPE_FACTORY_H

#include <string>
#include <map>
#include <vector>

#include "Shape.h"

class ShapeFactory
{
public:

   ShapeFactory(void);
   ~ShapeFactory(void);

   void insert(Shape* shape,const std::string& id);
   Shape* create(const std::string& id) const;

private:

   std::map<std::string,Shape*> store;
   std::vector<Shape*> garbage;
};

#endif
