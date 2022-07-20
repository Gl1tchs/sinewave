#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <transform.hpp>

class Object {
 public:
  virtual void tick();
  Transform transform;

 protected:
  void create(void (*obj)());
};

#endif  // OBJECT_HPP