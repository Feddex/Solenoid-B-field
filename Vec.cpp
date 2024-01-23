#include "Vec.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

Vec::Vec(double const &x, double const &y, double const &z)
    : _x{x}, _y{y}, _z{z} {}
double Vec::getX() const { return _x; }
double Vec::getY() const { return _y; }
double Vec::getZ() const { return _z; }
void Vec::setX(double const &x) { _x = x; }
void Vec::setY(double const &y) { _y = y; }
void Vec::setZ(double const &z) { _z = z; }
void Vec::set(double const &x, double const &y, double const &z) {
  _x = x;
  _y = y;
  _z = z;
}

Vec Vec::operator/(double const &a) const { return {_x / a, _y / a, _z / a}; }
Vec Vec::operator*(double const &a) const { return {_x * a, _y * a, _z * a}; }
Vec &Vec::operator+=(const Vec &other) {
  _x += other.getX();
  _y += other.getY();
  _z += other.getZ();
  return *this;
}

double Vec::norm() const {
  return std::sqrt(std::pow(_x, 2) + std::pow(_y, 2) + std::pow(_z, 2));
}

Vec Vec::versor() const { return *this / this->norm(); }

void Vec::print() const { std::cout << _x << " " << _y << " " << _z << '\n'; }

double VecOperation::distance(Vec const &a, Vec const &b) {
  double d = std::sqrt(std::pow(a.getX() - b.getX(), 2) +
                       std::pow(a.getY() - b.getY(), 2) +
                       std::pow(a.getZ() - b.getZ(), 2));
  return d;
}

Vec VecOperation::dist_vector(Vec const &a, Vec const &b) {
  return {a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()};
}

Vec VecOperation::crossProuct(Vec const &a, Vec const &b) {
  return {a.getY() * b.getZ() - a.getZ() * b.getY(),
          a.getZ() * b.getX() - a.getX() * b.getZ(),
          a.getX() * b.getY() - a.getY() * b.getX()};
}

Vec operator/(double const &a, Vec const &r) {
  return {r.getX() / a, r.getY() / a, r.getZ() / a};
}
Vec operator*(double const &a, Vec const &r) {
  return {r.getX() * a, r.getY() * a, r.getZ() * a};
}