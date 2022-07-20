#pragma once

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
