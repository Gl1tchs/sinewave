#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <shape.hpp>

class Pyramid : public IShape {
 public:
  Pyramid();
  virtual void display();

 private:
  float iteration;
  float rotation_y;
};

#endif  // TRIANGLE_HPP