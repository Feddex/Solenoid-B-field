#ifndef DATAGEN_HPP
#define DATAGEN_HPP

#include "Vec.hpp"
#include "Coil.hpp"
#include "BCalc.hpp"


#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>


void write_data(std::vector<Coil> const& conf);

#endif