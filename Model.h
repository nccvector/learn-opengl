//
// Author: Faizan Ali (github.com/nccvector)
// Date: 23/05/02
//

#ifndef OPENGL_FROM_SCRATCH_MODEL_H
#define OPENGL_FROM_SCRATCH_MODEL_H

#include <vector>

#include <glad/glad.h>

#include "Types.h"
#include "Material.h"

class Model {
public:
  Model( VertexList& vertices, UIntList& indices, PhongMaterial* material = nullptr )
      : mVertices( vertices ), mIndices( indices ), mMaterial( material ) {}

  void deviceLoad();

  [[maybe_unused]] void deviceUnload() {}

  inline glm::mat4& getTransform() {
    return mTransform4x4;
  }

  inline void setTransform( glm::mat4& transform ) {
    mTransform4x4 = transform;
  }

  inline PhongMaterial* getMaterial() {
    return mMaterial;
  }

  void _drawAndRelease();

  void _drawNoRelease();

  inline void _Release()
  {
    // Unbind VAOs
    glBindVertexArray( 0 ); // unbind
  }

private:
  VertexList mVertices    = {};
  UIntList mIndices       = {};
  glm::mat4 mTransform4x4 = glm::mat4( 1.0f );
  PhongMaterial* mMaterial;

  // OpenGL vars
  unsigned int mGlVBO {};
  unsigned int mGlVAO {};
  unsigned int mGlEBO {};
};


#endif // OPENGL_FROM_SCRATCH_MODEL_H
