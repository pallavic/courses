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


#include "Library.h"
#include "ShapeFactory.h"
#include "Square.h"
#include "Circle.h"

Library* Library::library = 0;

Library::Library(void)
{
   ShapeFactory::instance().insert(new Square,"square");
   ShapeFactory::instance().insert(new Circle,"circle");
}

Library& Library::instance(void)
{
   if (!library) library = new Library;
   return *library;
}

double Library::get_equivalent_length(const std::string& id_from,double length_from,const std::string& id_to) const
{
   Shape* shape_from = ShapeFactory::instance().create(id_from);
   shape_from->set_length(length_from);
   Shape* shape_to = ShapeFactory::instance().create(id_to);
   shape_to->set_equal_area(*shape_from);
   return shape_to->get_length();
}
