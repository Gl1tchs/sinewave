#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <object.hpp>

class Pyramid : public Object {
 public:
  Pyramid();
  virtual void tick();

  float iteration;
};

#endif  // TRIANGLE_HPP