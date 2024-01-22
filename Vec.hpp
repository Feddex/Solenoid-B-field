#ifndef VEC_HPP
#define VEC_HPP

#include <cassert>
#include <cmath>
#include <iostream>

class Vec {
 private:
  double _x;
  double _y;
  double _z;

 public:
  Vec(double const &x, double const &y, double const& z);
  double getX() const;
  double getY() const;
  double getZ() const;
  void setX(double const &x);
  void setY(double const &y);
  void setZ(double const& z);
  void set(double const &x, double const &y, double const& z);

  Vec operator/(double const &a) const;
  Vec operator*(double const &a) const;
  Vec& operator+=(const Vec& other);


  double norm() const;

  Vec versor() const;

  void print() const;
};

double distance(Vec const &a, Vec const &b);

// arrow point is the first point(vector) passed, the tail is the second one, this is like a difference bewteen vectors
Vec dist_vector(Vec const &a, Vec const &b);

//this return the cross product vector 
Vec crossProuct(Vec const &a, Vec const &b);

Vec operator/(double const &a, Vec const& r );
Vec operator*(double const &a, Vec const& r );

#endif