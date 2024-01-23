#include "Configuration.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "BCalc.hpp"
#include "Coil.hpp"
#include "DataGen.hpp"
#include "Vec.hpp"

std::vector<Coil> Configuration::config1(Coil const& coil) {
  // this givers the number of coils in the superior half part
  // of the solenoid,so you will have the basic coils whose centre is set at
  // (0,0,0) ad then we will have SupNumOfCoils on the left and SupNumOfCoils
  // on the right of this one. So in total you will have 2*SupNumOfCoils+1
  // coils.

  const int SupNumOfCoils = 1000;
  const double step = 0.01;

  std::vector<Coil> conf;
  for (int i{0}; i < 2 * SupNumOfCoils + 1; ++i) {
    Vec ith_centre = {coil.getCentre().getX() + step * (i - SupNumOfCoils),
                      coil.getCentre().getY(), coil.getCentre().getZ()};
    Coil cOil{coil.getRadius(), ith_centre, coil.getI()};
    conf.push_back(cOil);
  }

  return conf;
}