/*****************************************************************************
 *                                                                           *
 * Copyright (C) 2012-2015 Andrea Pallavicini                                *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              *
 * GNU General Public License for more details.                              *
 *                                                                           *
 *****************************************************************************/


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
