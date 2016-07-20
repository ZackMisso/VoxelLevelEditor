#ifndef __VIEW_H__
#define __VIEW_H__

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "../shaderClasses/shader.h"

class View {
private:
public:
  View();
  virtual ~View();
  virtual void display();
  virtual void reshape(int w,int h);
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(int x,int y);
  virtual void mouseClick(int button,int state,int x,int y);
  virtual void initialize();
  virtual void destroy();
};

#endif
