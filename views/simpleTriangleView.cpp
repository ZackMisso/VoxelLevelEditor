#include "simpleTriangleView.h"
#include <tgmath.h>
#include <iostream>

using namespace std;

SimpleTriangleView::SimpleTriangleView() {
	clearColor[0] = 0.0f;
	clearColor[1] = 0.0f;
	clearColor[2] = 0.0f;
	clearColor[3] = 1.0f;
}

void SimpleTriangleView::display() {
	glGetError();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearBufferfv(GL_COLOR,0,clearColor);
	double dt = (clock()-start)/(double)CLOCKS_PER_SEC*10;
	glUseProgram(simpleProgram);
	GLenum error = glGetError();
	GLfloat attrib[] = { (float)sin(dt) * 0.5f,
											 (float)cos(dt) * 0.6f,
											 0.0f, 0.0f };
	const GLfloat color[] = { (float)sin(dt) * 0.5f + 0.5f,
											 (float)cos(dt) * 0.5f + 0.5f,
										 	 0.0f, 1.0f };
	glPointSize(5.0);
	glVertexAttrib4fv(0,attrib);
	glVertexAttrib4fv(1,color);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glPatchParameteri(GL_PATCH_VERTICES,3);
	glDrawArrays(GL_PATCHES,0,3);

	error = glGetError();
	if(error != GL_NO_ERROR) {
		cout << "THERE WAS AN ERROR" << endl;
		if(error == GL_INVALID_ENUM) {
			cout << "INVALID ENUM" << endl;
		}
		if(error == GL_INVALID_VALUE) {
			cout << "INVALID VALUE" << endl;
		}
		if(error == GL_INVALID_OPERATION) {
			cout << "INVALID OPERATION" << endl;
		}
		if(error == GL_STACK_OVERFLOW) {
			cout << "STACK OVERFLOW" << endl;
		}
	}
}

void SimpleTriangleView::keyboard(int key,int scancode,int action,int mods) {
	// to be implemented
}

void SimpleTriangleView::initialize() {
	// initialize shaders
	simpleFrag = new FragShader();
	simpleVert = new VertShader();
	simpleTessC = new TessCShader();
	simpleTessE = new TessEShader();
	simpleGeom = new GeomShader();
	// read in the shader files
	simpleFrag->readFile("fragShaders/simpleTriangle.frag");
	simpleVert->readFile("vertShaders/simpleTriangle.vert");
	simpleTessC->readFile("tessControlShaders/simpleTriangle.tessc");
	simpleTessE->readFile("tessEvaluationShaders/simpleTriangle.tesse");
	simpleGeom->readFile("geomShaders/simpleTriangle.geom");
	// compile shaders
	//simpleProgram = Shader::compileShader(simpleVert,simpleFrag);
	//simpleProgram = Shader::compileShader(simpleVert,simpleFrag,simpleTessC,simpleTessE);
	simpleProgram = Shader::compileShader(simpleVert,simpleFrag,simpleTessC,simpleTessE,simpleGeom);
	// create and link empty vao
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	// set the start time
	start = clock();
}

void SimpleTriangleView::destroy() {
	glDeleteVertexArrays(1,&vao);
	glDeleteProgram(simpleProgram);
	glDeleteVertexArrays(1,&vao);
	simpleFrag->deleteShader();
	simpleVert->deleteShader();
}
