#ifndef BCALC_HPP
#define BCALC_HPP

#include "Coil.hpp"
#include "Vec.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

const double mu = 4 * M_PI * 1E-7;
const double dAlpha = 0.01; //step of integration
//double B = 0;

// this function will compute the infinitesimal contribute of a point on the
// circumference according to first Laplace's Law
Vec dB(Vec const &dTangentVector, Vec const &vect_distance_r,
          double const &I);

//this function computes the integral to get total B of a point given a coil, this is a partial B, just the contribute of one coil
Vec pB(Vec const &y, Coil const &coil);

//this computes the total B in a point given the solenoid (rapresented by the vector conf)
Vec tB(std::vector<Coil> const& conf, Vec const& y);




#endif