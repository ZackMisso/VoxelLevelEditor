#include "firstView.h"
#include <iostream>
#include <tgmath.h>

using namespace std;

FirstView::FirstView() {
  clearColor[0] = 0.0f;
  clearColor[1] = 0.0f;
  clearColor[2] = 0.0f;
  clearColor[3] = 1.0f;
}

void FirstView::display() {
  glPointSize(40.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glClearColor(clearColor[0],clearColor[1],clearColor[2],clearColor[3]);
	double dt = (clock()-start)/(double)CLOCKS_PER_SEC*100;
	//cout << dt << endl;
	const GLfloat color[] = { (float)sin(dt) * 0.5f + 0.5f,
														(float)cos(dt) * 0.5f + 0.5f,
														0.0f, 1.0f };
	//glClearBufferfv(GL_COLOR,0,color);
  glClearBufferfv(GL_COLOR,0,clearColor);
	glUseProgram(renderProgram);
  glDrawArrays(GL_POINTS,0,1);
}

void FirstView::reshape(int w,int h) {
  glViewport(0,0,w,h);
}

void FirstView::keyboard(int key,int scancode,int action,int mods) {
  // probably will do nothing
}

void FirstView::mouseMove(int x,int y) {
  // probably will do nothing
}

void FirstView::mouseClick(int button,int state,int x,int y) {
  // probably will do nothing
}

void FirstView::initialize() {
  // initialize shaders
  frag = new FragShader();
  vert = new VertShader();
  // read in the shader files
  frag->readFile("fragShaders/pos.frag");
  vert->readFile("vertShaders/pos.vert");
  // compile shaders
  renderProgram = Shader::compileShader(vert,frag);
  // create and link empty vao
  glGenVertexArrays(1,&vao);
  glBindVertexArray(vao);
	// set the start time
	start = clock();
}

void FirstView::destroy() {
  glDeleteVertexArrays(1,&vao);
  glDeleteProgram(renderProgram);
  glDeleteVertexArrays(1,&vao);
  frag->deleteShader();
  vert->deleteShader();
}
