#ifndef SHADER_ABSTRACTION_SHADER_H
#define SHADER_ABSTRACTION_SHADER_H

#include "Model.h"
#include "Camera.h"

class Shader {
public:
  Shader()  = default;
  ~Shader() = default;

  void Draw(Camera* camera, Model* model);

  void destroy() {
    glDeleteProgram( program );
  }

protected:
  void loadAndCompile( const char* path, unsigned int shader );

public:
  unsigned int program;
};

class PhongShader : public Shader {
public:
  PhongShader();
};

#endif // SHADER_ABSTRACTION_SHADER_H