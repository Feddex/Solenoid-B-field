#include "Coil.hpp"

Coil::Coil(double const &radius, Vec const &centre, double const &i)
    : _Radius{radius}, _Centre{centre}, _I{i} {
  assert(radius > 0);
}

Coil &Coil::operator=(const Coil &other) {
  if (this != &other) {
    _Radius = other._Radius;
    _Centre = other._Centre;
    _I = other._I;
  }
  return *this;
}

double Coil::getRadius() const { return _Radius; }

Vec Coil::getCentre() const { return _Centre; }

double Coil::getI() const { return _I; }

Vec Coil::pointOnCirc(double alpha) const {
  return {_Centre.getX(), _Radius * std::cos(alpha), _Radius * std::sin(alpha)};
}

Vec Coil::TangentVersor(Vec const &PointOnCirc) const {
  Vec CentreToPointVec = VecOperation::dist_vector(PointOnCirc, _Centre);
  Vec TangentVector = {
      PointOnCirc.getX(), -CentreToPointVec.getZ(),
      CentreToPointVec
          .getY()};  // it's a perpendicular vector to the previous one, the
                     // norm of this vector is the same of the previous one, if
                     // the coordinates of the previous vector were (x,y,z) the
                     // tangent vector has (x,-z,y) components
  return TangentVector.versor();
}