/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _LIBRARY_H
#define _LIBRARY_H

#include<string>

class Library
{
public:

   Library(void);

   static Library& instance(void);

   double get_equivalent_length(const std::string& id_from,double length_from,const std::string& id_to) const;

private:

   static Library* library;
};

#endif
