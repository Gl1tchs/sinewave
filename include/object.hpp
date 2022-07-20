#pragma once

#include <transform.hpp>

class Object {
 public:
  virtual void tick();
  Transform transform;

 protected:
  void create(void (*obj)());
};
