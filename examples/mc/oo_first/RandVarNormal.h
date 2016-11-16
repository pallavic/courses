/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _RANDVAR_NORMAL_H
#define _RANDVAR_NORMAL_H

#include "RandVar.h"

class RandVarNormal : public RandVar
{
public:
   
   RandVarNormal(double m=0.0,double s=1.0);
   virtual ~RandVarNormal(void) {}
   
   virtual double draw(void);
   
private:
   
   static const double pi;
   
   double m, s;
};

#endif
