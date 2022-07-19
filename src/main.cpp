#include <GL/glut.h>

#include <cmath>
#include <memory>
#include <pyramid.hpp>
#include <shape.hpp>
#include <string>
#include <vector>

std::vector<IShape*> shapes{};
unsigned int refresh_mills{15};
float iteration{0.0f};

void init_config() {
  glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(refresh_mills, timer, 0);
}

void reshape(GLsizei width, GLsizei height) {
  if (height == 0) height = 1;
  GLfloat aspect{(GLfloat)width / (GLfloat)height};

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void display() {
  for (auto shape : shapes) {
    shape->display();
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Sine Wave");

  Pyramid* pyramid = new Pyramid();

  shapes.push_back(pyramid);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  init_config();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}