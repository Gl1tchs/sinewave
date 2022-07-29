#include <GL/glut.h>

#include <cmath>
#include <iostream>
#include <memory>
#include <object.hpp>
#include <pyramid.hpp>
#include <string>
#include <vector>

/**
 * @brief Objects in the space.
 *
 */
static std::vector<Object*> objects{};

/**
 * @brief Initializes window.
 *
 */
void init_config() {
  glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/**
 * @brief Triggered in at least `value` milliseconds.
 *
 * @param value as milliseconds.
 */
void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(15, timer, 0);
}

/**
 * @brief Handles reshape events from current window.
 *
 * @param width Window width
 * @param height Window height
 */
void handle_reshape_event(GLsizei width, GLsizei height) {
  if (height == 0) height = 1;
  GLfloat aspect{(GLfloat)width / (GLfloat)height};

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/**
 * @brief Called every frame
 *
 */
void tick() {
  for (auto shape : objects) {
    shape->tick();
  }
}

/**
 * @brief True if alt key pressed.
 *
 */
bool alt_key_pressed{false};

/**
 * @brief Handles keyboard events from current window.
 *
 * @param key Pressed key
 * @param x  Mouse x location
 * @param y  Mouse y location
 */
void handle_keyboard_events(unsigned char key, int x, int y) {
  switch (key) {
    case GLUT_ACTIVE_ALT:
      alt_key_pressed = true;
      break;
    case 27:
      // Exit program if esc key pressed.
      exit(EXIT_SUCCESS);
    default:
      if (alt_key_pressed) {
        // If alt key pressed set it to false
        alt_key_pressed = false;
      }
  }
}

/**
 * @brief Handles keyboard events from special keys in current window
 *
 * @param key Pressed key
 * @param x Mouse x location
 * @param y Mouse y location
 */
void handle_special_key_events(int key, int x, int y) {
  // Alt + F4 exit event.
  if (alt_key_pressed && key == GLUT_KEY_F4) {
    exit(0);
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Sine Wave");

  // Create a pyramid object.
  Pyramid* pyramid = new Pyramid();

  // Push it to shapes vector.
  objects.push_back(pyramid);

  // Assign functions.
  glutDisplayFunc(tick);
  glutSpecialFunc(handle_special_key_events);
  glutKeyboardFunc(handle_keyboard_events);
  glutReshapeFunc(handle_reshape_event);

  // Initialize window.
  init_config();
  std::cout << "\033[32mAnimation started..\033[0m\n"
            << "Press `esc` to quit!\n";

  glutTimerFunc(0, timer, 0);

  // Start program loop.
  glutMainLoop();

  return EXIT_SUCCESS;
}