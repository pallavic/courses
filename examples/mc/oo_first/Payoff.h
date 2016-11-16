/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _PAYOFF_H
#define _PAYOFF_H

#include "MCPath.h"
#include<utility>

class MCEngine;

class Payoff
{
public:
   
   virtual ~Payoff(void) {}
   
   virtual double evaluate(const MCPath& path) const =0;
   virtual std::pair<double,double> price(MCEngine& engine) const =0;
};

#endif
