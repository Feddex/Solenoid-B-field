#include "BCalc.hpp"

#include <vector>

#include "Coil.hpp"
#include "Vec.hpp"

Vec dB(Vec const &dTangentVector, Vec const &vect_distance_r, double const &I) {
  double distance_r = vect_distance_r.norm();
  Vec vers_distance_r = vect_distance_r.versor();
  Vec dB=
      (mu * I * (crossProuct(dTangentVector, vers_distance_r))) /
      (4 * M_PI * std::pow(distance_r, 2));
  return dB;
}

Vec pB(Vec const &y, Coil const &coil) {
  double alpha = 0;
  Vec B = {0, 0, 0};
  double I = coil.getI();
  double arc_len = coil.getRadius() * dAlpha;
  while (alpha < 2 * M_PI) {
    // this is the point on the circumference
    Vec pointOnCirc = coil.pointOnCirc(alpha);
    Vec tangentVersor = coil.TangentVersor(pointOnCirc);
    Vec dTangentVector = tangentVersor * arc_len;
    // vector distance between the point on the circ and
    // the point y where I want to mesure the B field
    Vec vect_distance_r = dist_vector(y, pointOnCirc);
    B += dB(dTangentVector, vect_distance_r, I);
    alpha += dAlpha;
  }
  return B;
}

Vec tB(std::vector<Coil> const &conf, Vec const &y) {
  Vec totB{0, 0, 0};
  const int size = conf.size();
  for (int i{0}; i < size; ++i) {
    totB += pB(y, conf[i]);
  }
  return totB;
}