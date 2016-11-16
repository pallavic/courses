/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _BLACK_H
#define _BLACK_H

#include "MCEngine.h"

class Black : public MCEngine
{
public:

   Black(double volatility,unsigned long nstate=1000);
   virtual ~Black(void) {}
   
   virtual void fill_path(const std::vector<double>& times,MCPath& path) const;

private:

   double volatility;
};

#endif
