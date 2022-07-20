#pragma once

/**
 * @brief Stores objects position.
 * 
 */
struct Position {
  float x, y, z;
};

/**
 * @brief Stores objects rotation.
 * 
 */
struct Rotation {
  float x, y, z;
};

/**
 * @brief Stores objects transform.
 *
 */
struct Transform {
  Position position;
  Rotation rotation;
};
