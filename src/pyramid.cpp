#include <GL/glut.h>

#include <cmath>
#include <color.hpp>
#include <iostream>
#include <pyramid.hpp>

Pyramid::Pyramid() : m_iteration(0.0f) {
  // Set initiazl Z position of the object.
  transform.position.z = -8.0f;
}

void Pyramid::tick() {
  // Call base tick function.
  Object::tick();

  m_iteration += 0.01f;

  // The actual wave animation.
  transform.position.y = sin(m_iteration);

  // Rotate object by Y axis.
  transform.rotation.y += 0.8f;

  // Create actual pyramid vertices
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

  // Double buffer
  glutSwapBuffers();
}
