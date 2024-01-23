#include "DataGen.hpp"

#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>

#include "BCalc.hpp"
#include "Coil.hpp"
#include "Configuration.hpp"
#include "Vec.hpp"

void write_data(std::vector<Coil> const& conf) {
  const int size = conf.size();
  Coil mainCoil =
      conf[((size + 1) / 2) - 1];  // this should hand the central coil which is
                                   // the one whose centre is set to 0,0,0
  assert(mainCoil.getCentre().getX() == 0 && mainCoil.getCentre().getY() == 0 &&
         mainCoil.getCentre().getZ() == 0);
  double R = mainCoil.getRadius();

  std::default_random_engine eng;
  std::uniform_real_distribution<> roll_dice(0., 1.);

  std::ofstream of1("Bx.txt");
  std::ofstream of2("By.txt");
  std::ofstream of3("Bz.txt");

  for (int i{0}; i < 1E2; ++i) {
    double g = roll_dice(eng);
    Vec p{mainCoil.getCentre().getX(), 2 * R * g,
          mainCoil.getCentre().getZ()};  // we take p on the y axis
    Vec B = BCalc::tB(conf, p);

    of1 << p.getY() << " " << B.getX() << '\n';
    of2 << p.getY() << " " << B.getY() << '\n';
    of1 << p.getY() << " " << B.getZ() << '\n';
  }
}