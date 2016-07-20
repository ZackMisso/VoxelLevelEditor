#ifndef __FIRSTVIEW_H__
#define __FIRSTVIEW_H__

// This View Just Displays a Single Point. This View is used to test my initial setup

#include "view.h"
#include "../shaderClasses/fragShader.h"
#include "../shaderClasses/vertShader.h"
#include <ctime>

class FirstView : public View {
private:
  FragShader* frag;
  VertShader* vert;
  GLfloat clearColor[4];
  GLuint renderProgram;
  GLuint vao;
	clock_t start;
public:
  FirstView();
  virtual void display();
  virtual void reshape(int w,int h);
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseMove(int x,int y);
  virtual void mouseClick(int button,int state,int x,int y);
  virtual void initialize();
  virtual void destroy();
};

#endif
