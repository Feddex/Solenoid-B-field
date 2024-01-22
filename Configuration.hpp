#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

#include "BCalc.hpp"
#include "Coil.hpp"
#include "DataGen.hpp"
#include "Vec.hpp"

// step will be the coil density (we will have one coil per step)
std::vector<Coil> config1(Coil const& coil);

#endif