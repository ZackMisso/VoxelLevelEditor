// This Project is all my messing around with Modern OpenGL
#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "views/viewController.h"

// debug
#include <iostream>
using namespace std;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);
void error(int error, const char* description);

// variables
ViewController* viewController;

int main(int argc,char** argv) {
  if(!glfwInit())
    exit(EXIT_FAILURE);
  glfwSetErrorCallback(error);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  GLFWwindow* window = glfwCreateWindow(1000,1000,"Zack Misso - ModernGL",NULL,NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  int width;
  int height;
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window,keyboard);
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0,0,width,height);
  glfwSwapInterval(0);

	ViewController::initialize();
  viewController = ViewController::getInstance();

  while (!glfwWindowShouldClose(window))
  {
    // Main Loop
    display();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}

void display() {
	viewController->getCurrentView()->display();
}

void reshape(int w,int h) {
	glViewport(0,0,w,h);
}

void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
    glfwSetWindowShouldClose(window,GL_TRUE);
  viewController->getCurrentView()->keyboard(key,scancode,action,mods);
}

void mouseMove(int x,int y) {
	viewController->getCurrentView()->mouseMove(x,y);
}

void mouseClick(int button,int state,int x,int y) {
	viewController->getCurrentView()->mouseClick(button,state,x,y);
}

void error(int error, const char* description) {
  fputs(description, stderr);
}
