#include "DataGen.hpp"

#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>

#include "BCalc.hpp"
#include "Spiral.hpp"
#include "Vec.hpp"

void write_data(Spiral const& spiral) {
  // const int size = conf.size();
  // Coil mainCoil =
  //     conf[((size + 1) / 2) - 1];  // this should hand the central coil which
  //     is
  //                                  // the one whose centre is set to 0,0,0
  // assert(mainCoil.getCentre().getX() == 0 && mainCoil.getCentre().getY() == 0
  // &&
  //        mainCoil.getCentre().getZ() == 0);
  // double R = mainCoil.getRadius();

  double R = spiral.getRadius();

  std::default_random_engine eng;
  std::uniform_real_distribution<> roll_dice(0., 1.);

  std::ofstream of1("Bx.txt");
  std::ofstream of2("By.txt");
  std::ofstream of3("Bz.txt");

  for (int i{0}; i < 100; ++i) {
    double g = roll_dice(eng);
    Vec p{spiral.getCentre().getX(), 2 * R * g,
          spiral.getCentre().getZ()};  // we take p on the y axis
    
    // Vec p{spiral.getCentre().getX() + g * spiral.getSupHalfLenght(),
    //       spiral.getCentre().getY(), spiral.getCentre().getZ()};
    Vec B = BCalc::pB(p, spiral);

    of1 << p.getY() << " " << B.getX() << '\n';
    of2 << p.getY() << " " << B.getY() << '\n';
    of1 << p.getY() << " " << B.getZ() << '\n';
  }
}