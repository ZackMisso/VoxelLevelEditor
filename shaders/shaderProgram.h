#pragma once

class ShaderProgram {
private:
  Shader* vert;
  Shader* frag;
  Shader* tessE;
  Shader* tessC;
  Shader* geom;
  Shader* comp;
  GLuint program;
  bool ownsShaders;
public:
  ShaderProgram();
  ~ShaderProgram();
  void compileAndLink();
  void detachShaders();
  void deleteProgram();
  void programOwnsShaders(bool param);
  void checkCompileLog(const GLuint shader);
  // getter methods
  VertShader* getVert();
  FragShader* getFrag();
  TessEShader* getTessE();
  TessCShader* getTessC();
  GeomShader* getGeom();
  ComputeShader* getComp();
  // setter methods
  void setVert(VertShader* param);
  void setFrag(FragShader* param);
  void setTessE(TessEShader* param);
  void setTessC(TessCShader* param);
  void setGeom(GeomShader* param);
  void setComp(ComputeShader* param);
};
