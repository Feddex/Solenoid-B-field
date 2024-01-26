#include "Spiral.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

#include "Configuration.hpp"
#include "DataGen.hpp"
#include "Vec.hpp"

Spiral::Spiral(Vec const &centre, double const &radius,
               double const &elicoidalstep, double const &suplengh,
               double const &i)
    : _Centre{centre},
      _FixedRadius{radius},
      _ElicoidalStep{elicoidalstep},
      _SupHalfLenght{suplengh},
      _I{i} {
  assert(_FixedRadius > 0);
  assert(_ElicoidalStep > 0);
  assert(_SupHalfLenght > 0);
}

Vec Spiral::getCentre() const { return _Centre; }
double Spiral::getFixedRadius() const { return _FixedRadius; }
double Spiral::getElicoidalStep() const { return _ElicoidalStep; }
double Spiral::getI() const { return _I; }
double Spiral::getSupHalfLenght() const { return _SupHalfLenght; }
double Spiral::getRadius(double const &t) const {
  //custom function tha determs the radius size of the solenoid, it's a fuction of t, the parameter of the parametrization of the curve
  return _FixedRadius*(std::sin(2*M_PI*t)+1);
};

void Spiral::setCentre(Vec const &centre) { _Centre = centre; }
void Spiral::setFixedRadius(double const &radius) { _FixedRadius = radius; }
void Spiral::setElicoidalStep(double const &elicoidalstep) {
  _ElicoidalStep = elicoidalstep;
}
void Spiral::setSupHalfLenght(double const &supLengt) {
  _SupHalfLenght = supLengt;
}
void Spiral::setI(double const &i) { _I = i; }

double Spiral::getNumOfCoils() const {
  return (_SupHalfLenght / _ElicoidalStep) * 2;
}
double Spiral::getSupNumOfCoils() const { return getNumOfCoils() / 2; }
Vec Spiral::getPointOnSpiral(double const &t) const {
  return {_ElicoidalStep * t + _Centre.getX(),
          this->getRadius(t) * std::cos(2 * M_PI * t) + _Centre.getY(),
          this->getRadius(t) * std::sin(2 * M_PI * t) + _Centre.getZ()};
}
Vec Spiral::getTanegtVersor(double const &t) const {
  Vec gradient{
      _ElicoidalStep, -2 * M_PI * _FixedRadius * std::sin(2 * M_PI * t),
      2 * M_PI * _FixedRadius *
          std::cos(
              2 * M_PI *
              t)};  // this the gradient of the parametrization evaluated at t
  return gradient.versor();
}

double Spiral::getInfinitesimalArchLenght(double const &dt) const {
  return std::sqrt(std::pow(_ElicoidalStep, 2) +
                   std::pow(2 * M_PI * _FixedRadius, 2)) *
         dt;
}  // this lengh dipends on the dt only, and not on the point where i calculate