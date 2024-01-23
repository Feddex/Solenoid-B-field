#ifndef BCALC_HPP
#define BCALC_HPP

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "Spiral.hpp"
#include "Vec.hpp"



const double mu = 4 * M_PI * 1E-7;
const double dt = 0.01;  // step of integration, small change in the parameter t of the parametrization of the curve 


class BCalc {
 public:
  // this function will compute the infinitesimal contribute of a point on the
  // spiral according to first Laplace's Law
  static Vec dB(Vec const &dTangentVector, Vec const &vect_distance_r,
                double const &I);

  // this function computes the integral to get total B of a point given a coil,
  // this is a partial B, just the contribute of one coil
  static Vec pB(Vec const &y, Spiral const &spiral);

  // this computes the total B in a point given the solenoid (rapresented by the
  // vector conf)
  //static Vec tB(std::vector<Coil> const &conf, Vec const &y);
};

#endif