#include <GL/glut.h>

#include <object.hpp>

void Object::tick() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  glTranslatef(transform.position.x, transform.position.y,
               transform.position.z);

  glRotatef(transform.rotation.x, 1.0f, 0.0f, 0.0f);
  glRotatef(transform.rotation.y, 0.0f, 1.0f, 0.0f);
  glRotatef(transform.rotation.z, 0.0f, 0.0f, 1.0f);
}