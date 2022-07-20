#pragma once

#include <object.hpp>

/**
 * @brief An pyramid object to display.
 *
 */
class Pyramid : public Object {
 public:
  Pyramid();

  /**
   * @brief Called every frame.
   *
   */
  virtual void tick();

  /**
   * @brief Current iteration triggered by tick function.
   *
   */
  float iteration;
};
