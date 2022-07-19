#include <GL/glut.h>

#include <cmath>
#include <memory>
#include <pyramid.hpp>
#include <shape.hpp>
#include <string>
#include <vector>

GLfloat rotation_y{0.0f};
GLfloat position_y{0.0f};
int refreshMills{15};
float iteration{0.0f};
std::vector<IShape*> shapes{};

void init() {
  glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(refreshMills, timer, 0);
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
  init();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}