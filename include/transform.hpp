#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

struct Position {
  float x, y, z;
};

struct Rotation {
  float x, y, z;
};

class Transform {
 public:
  Position position;
  Rotation rotation;
};

#endif  // TRANSFORM_HPP