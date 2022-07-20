#include <GL/glut.h>

#include <cmath>
#include <color.hpp>
#include <iostream>
#include <pyramid.hpp>

Pyramid::Pyramid() : iteration(0.0f) { transform.position.z = -6.0f; }

void Pyramid::tick() {
  Object::tick();

  iteration += 0.01f;

  transform.position.y = sin(iteration);
  transform.rotation.y += 0.8f;
  
  Object::create([]() {
    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);  // yellow
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(1.0f, -1.0f, 1.0f);

    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);  // yellow
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(1.0f, -1.0f, -1.0f);

    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);  // yellow
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);  // yellow
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // red
    glVertex3f(-1.0f, -1.0f, 1.0f);
  });

  glutSwapBuffers();
}
