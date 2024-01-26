#ifndef SPIRAL_HPP
#define SPIRAL_HPP

#include <cassert>
#include <cmath>
#include <iostream>

#include "Vec.hpp"

// n this program the spiral will be coiled around x_axis, the current is
// positive if it's spinning anti-clockwise the centre of the solenoid is given
// by the vector _Cntre so it will be simmetrical with respect to that point

class Spiral {
 private:
  Vec _Centre;
  double _FixedRadius;
  double _ElicoidalStep;  // this is actually the distance of two consecutive
                          // heads of the elic, this can be use to evaluate coil
                          // density: 1/elicoidalstep
  double _SupHalfLenght;  // this is the lenght of the superior part of the
                          // solenoid, lenght between the centre and the
                          // superior extrem of the solenoid, so it's half of
                          // the total lenght
  double _I;

 public:
  Spiral(Vec const &centre, double const &radius, double const &elicoidalstep,
         double const &suplengh, double const &i);

  Vec getCentre() const;
  double getFixedRadius() const;
  double getElicoidalStep() const;
  double getI() const;
  double getSupHalfLenght() const;

  double getRadius(double const &t) const;

  void setCentre(Vec const &centre);
  void setFixedRadius(double const &radius);
  void setElicoidalStep(double const &elicoidalstep);
  void setSupHalfLenght(double const &supLengt);
  void setI(double const &i);

  double getNumOfCoils()
      const;  // this is the number of coils becouse a coil occupies a space
              // equivalent to _ElicoidalStep
  double getSupNumOfCoils()
      const;  // this is the number of coils in the superior part of the
              // solenoid, it's also equivalent to the max value of the
              // parameter t in the parametrization of the elic-line
  Vec getPointOnSpiral(double const &t)
      const;  // this functions returns a point on the sprial, this is the
              // evaluation of the parametrization of the curve at point t
  Vec getTanegtVersor(
      double const &t) const;  // this function returns a tangent versor to the
                               // elic in the point given by the evaluation of
                               // parameter t in the elic parametrization
  double getInfinitesimalArchLenght(double const &dt)
      const;  // this function return the infinitesimal arch lenght of the
              // spiral between to points P(t) and P(t+dt) where P is the
              // parametrization of the spiral
};

#endif