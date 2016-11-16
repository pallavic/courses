/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _RANDVAR_H
#define _RANDVAR_H

class RandVar
{
public:
   
   virtual ~RandVar(void) {}
   
   virtual double draw(void) =0;
};

#endif
