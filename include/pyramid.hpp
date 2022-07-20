#pragma once

#include <object.hpp>

class Pyramid : public Object {
 public:
  Pyramid();
  virtual void tick();

  float iteration;
};
