#include "Coil.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

#include "BCalc.hpp"
#include "Configuration.hpp"
#include "DataGen.hpp"
#include "Vec.hpp"

// this program computes the B field in a point y given a solenoid whose axe is
// oriented as the x-axes. if you want to simulate an indefinite solenoid,
// elongate the ends of the solenoid adding more coils in configuration
// (SupNumOfCoils) and to abtain a better approximation set y{0,y,0}; so that it
// will be centred to the solenoid and the configuration is simetric.
// the current will be positive if flowing anti-clockwise as canonical
// orientation imposes

int main() {
  // //SINGLE TRIAL
  // Coil coil{1, {0, 0, 0}, 1};
  // std::vector<Coil> conf = config1(coil);
  // //CHNAGE THE POINT NOT THE CENTRE OF THE COIL
  // Vec y{0, 0, 0};
  // Vec B = tB(conf, y);
  // B.print();

  // MULTIPLE TRIAL
  Coil coil{1, {0, 0, 0}, 1};
  std::vector<Coil> conf = Configuration::config1(coil);
  write_data(conf);
}