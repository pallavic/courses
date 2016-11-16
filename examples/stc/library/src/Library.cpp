/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

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
