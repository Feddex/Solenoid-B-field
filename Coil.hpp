#ifndef COIL_HPP
#define COIL_HPP

#include <cassert>
#include <cmath>
#include <iostream>

#include "Vec.hpp"

// in this program the centre of the coil is set to be (0,0,0) and its axe is
// x-axes in such a way that the current is positive if its spinning
// anti-clockwise
class Coil {
 private:
   double _Radius;
   Vec _Centre;
   double _I;  // it can also be negative, its positive if its spinning
                    // anti-clockwise

 public:
  Coil();
  Coil(double const &radius, Vec const &centre, double const &i);

  Coil &operator=(const Coil &other);

  double getRadius() const;

  Vec getCentre() const;

  double getI() const;

  // this returns a point on the circumference given the aplha coordinate
  Vec pointOnCirc(double alpha) const;

  // this returns the canonic tangent versor to the circumference at a given
  // point
  Vec TangentVersor(Vec const &PointOnCirc) const;
};

#endif