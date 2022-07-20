#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <object.hpp>

class Pyramid : public Object {
 public:
  Pyramid();
  virtual void display();

 private:
  float iteration;
  float rotation_y;
};

#endif  // TRIANGLE_HPP