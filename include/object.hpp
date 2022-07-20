#pragma once

#include <transform.hpp>

class Object {
 public:
  /**
   * @brief Called every frame.
   *
   */
  virtual void tick();

  /**
   * @brief Transform of the object in the space.
   *
   */
  Transform transform;

 protected:
  /**
   * @brief Creates opengl object.
   *
   * @param object Triangles as function.
   */
  void create(void (*object)());
};
