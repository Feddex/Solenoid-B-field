#include <cassert>
#include <cmath>
#include <iostream>

#include "BCalc.hpp"
#include "Configuration.hpp"
#include "DataGen.hpp"
#include "Vec.hpp"
#include "Spiral.hpp"

// this program computes the B field in a point y given a solenoid whose axe is
// oriented as the x-axes. if you want to simulate an indefinite solenoid,
// elongate the ends of the solenoid by adding more coils in configuration
// (SupNumOfCoils) and to abtain a better approximation set y{0,y,0}; so that it
// will be centred to the solenoid and the configuration is simetric.
// the current will be positive if flowing anti-clockwise as canonical
// orientation imposes

int main() {
  // //SINGLE TRIAL
  //   Spiral spiral{{0, 0, 0}, 1, 0.01, 5, 1};
  //   Vec y{0, 0, 0};
  //   Vec B = BCalc::pB(y, spiral);
  //   B.print();
    

//   // MULTIPLE TRIAL
  Spiral spiral{{0, 0, 0}, 1, 0.01, 5, 1};
  write_data(spiral);
}