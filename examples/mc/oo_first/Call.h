/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _CALL_H
#define _CALL_H

#include "Payoff.h"

class Call : public Payoff
{
public:
   
   Call(double strike,double maturity);
   virtual ~Call(void) {}
   
   virtual double evaluate(const MCPath& path) const;
   virtual std::pair<double,double> price(MCEngine& engine) const;
   
private:
   
   double strike, maturity;
};

#endif
