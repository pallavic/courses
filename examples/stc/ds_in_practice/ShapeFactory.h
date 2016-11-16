/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

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
