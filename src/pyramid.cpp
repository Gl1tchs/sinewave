#include <GL/glut.h>

#include <cmath>
#include <color.hpp>
#include <iostream>
#include <pyramid.hpp>

Pyramid::Pyramid() : iteration(0.0f), rotation_y(0.0f) {}

void Pyramid::display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  iteration += 0.01f;

  glTranslatef(0.0f, sin(iteration), -6.0f);

  glRotatef(rotation_y, 0.0f, 1.0f, 0.0f);
  rotation_y += 0.8f;

  glBegin(GL_TRIANGLES);

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

  glEnd();

  glutSwapBuffers();
}
