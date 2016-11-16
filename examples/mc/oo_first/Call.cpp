/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#include "Call.h"
#include "MCEngine.h"
#include<stdexcept>

Call::Call(double strike,double maturity)
{
   const double epsilon = 1.e-15;

   if (strike<epsilon) throw std::range_error("stock's price must be positive");
   this->strike = strike;
   
   if (maturity<-epsilon) throw std::range_error("option's maturity cannot be negative");
   this->maturity = std::max(0.0,maturity);
}

double Call::evaluate(const MCPath& path) const
{
   if (path.size()!=1) throw std::range_error("stock price's simulation path must have only one simulation date");

   const double payoff = std::max(path[0]-strike,0.0);
   
   return payoff;
}

std::pair<double,double> Call::price(MCEngine& engine) const
{
   engine.init(std::vector<double>(1,maturity));
   return engine.price(*this);
}
