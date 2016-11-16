/*
 * (C) Copyright Andrea Pallavicini, 2010.
 *
 * Distributed under the GNU General Public License, Version 3.0.
 * See accompanying file COPYING or copy at http://www.gnu.org/licenses/gpl.txt
 *
 */

#ifndef _MC_H
#define _MC_H

void mc_sim_call(double S,double K,double vol,double T,unsigned long n,unsigned long k,double& price,double& error);

#endif
