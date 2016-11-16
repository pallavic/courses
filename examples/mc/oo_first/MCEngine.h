/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _MCENGINE_H
#define _MCENGINE_H

#include "MCPath.h"
#include<utility>
#include<vector>

class Payoff;

class MCEngine
{
public:

   MCEngine(unsigned long nstate=1000);
   virtual ~MCEngine(void) {}
   
   void init(const std::vector<double>& simultation_time);

   std::pair<double,double> price(const Payoff& payoff);

   virtual void fill_path(const std::vector<double>& times,MCPath& path) const =0;

private:

   unsigned long nstate;
   std::vector<double> times;
};

#endif
