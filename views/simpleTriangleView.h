#pragma once

// This View Displays a Single Triangle

#include "view.h"
#include "../shaderClasses/fragShader.h"
#include "../shaderClasses/vertShader.h"
#include "../shaderClasses/tessCShader.h"
#include "../shaderClasses/tessEShader.h"
#include "../shaderClasses/geomShader.h"
#include <ctime>

class SimpleTriangleView : public View {
private:
	FragShader* simpleFrag;
	VertShader* simpleVert;
	TessCShader* simpleTessC;
	TessEShader* simpleTessE;
	GeomShader* simpleGeom;
	GLfloat clearColor[4];
	GLuint simpleProgram;
	GLuint vao;
	clock_t start;
public:
	SimpleTriangleView();
	virtual void display();
	virtual void keyboard(int key,int scancode,int action,int mods);
	virtual void initialize();
	virtual void destroy();
};
