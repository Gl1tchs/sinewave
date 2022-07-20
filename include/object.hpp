#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <transform.hpp>

class Object {
 public:
  virtual void display();
  Transform transform;
};

#endif  // OBJECT_HPP