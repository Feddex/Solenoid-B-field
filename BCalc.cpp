#include "BCalc.hpp"

#include <vector>


#include "Spiral.hpp"
#include "Vec.hpp"

Vec BCalc::dB(Vec const &dTangentVector, Vec const &vect_distance_r,
              double const &I) {
  double distance_r = vect_distance_r.norm();
  Vec vers_distance_r = vect_distance_r.versor();
  Vec dB =
      (mu * I * (VecOperation::crossProuct(dTangentVector, vers_distance_r))) /
      (4 * M_PI * std::pow(distance_r, 2));
  return dB;
}

Vec BCalc::pB(Vec const &y, Spiral const &spiral) {
  double tMax= spiral.getSupNumOfCoils();//this is the max value we can assign to paramter t, the minimum value is -tMax because the spiral is simetric with respect to the centre
  double t=-tMax;
  Vec B = {0, 0, 0};
  double I = spiral.getI();
  double arc_len = spiral.getInfinitesimalArchLenght(dt);
  while (t < tMax) {
    // this is the point on the circumference
    Vec pointOnSpiral = spiral.getPointOnSpiral(t);
    Vec tangentVersor = spiral.getTanegtVersor(t);
    Vec dTangentVector = tangentVersor * arc_len;
    // vector distance between the point on the circ and
    // the point y where I want to mesure the B field
    Vec vect_distance_r = VecOperation::dist_vector(y, pointOnSpiral);
    B += dB(dTangentVector, vect_distance_r, I);
    t += dt;
  }
  return B;
}

// Vec BCalc::tB(std::vector<Coil> const &conf, Vec const &y) {
//   Vec totB{0, 0, 0};
//   const int size = conf.size();
//   for (int i{0}; i < size; ++i) {
//     totB += pB(y, conf[i]);
//   }
//   return totB;
// }