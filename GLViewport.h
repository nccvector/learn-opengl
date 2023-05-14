//
// Author: Faizan Ali (github.com/nccvector)
// Date: 23/05/14
//

#ifndef OPENGL_FROM_SCRATCH_GLVIEWPORT_H
#define OPENGL_FROM_SCRATCH_GLVIEWPORT_H

#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>

#include "Texture.h"
#include "FrameBuffer.h"
#include "Model.h"
#include "Material.h"
#include "Camera.h"

class GLViewport {
public:
  GLViewport( int width, int height ) {
    mWidth  = width;
    mHeight = height;
    mCamera = nullptr;

    // Initializing frame buffer and renderTexture
    mFramebuffer = std::make_unique<FrameBuffer>();

    // Initialize render texture
    mRenderTexture = { "Application Render", TextureType::Ambient, width, height, 4 };
    TextureTools::GenTextureOnDevice( mRenderTexture );
    mFramebuffer->addRenderTexture( mRenderTexture );
    assert( mFramebuffer->complete() );
  }

  void setCamera( Camera* camera ) {
    mCamera = camera;
  }


  void resize( int width, int height ) {
    mWidth  = width;
    mHeight = height;

    // RESIZE CAMERA???
  }

  void draw( const std::vector<Model>& models, const std::vector<Material>& materials,
      const std::vector<PointLight> pointlights, std::shared_ptr<Shader> shader ) {

    if (mCamera == nullptr)
    {
      std::cerr << "Camera is NULL" << std::endl;
      return;
    }

    // Bind render frame buffer before drawing scene
    // Render to our framebuffer
    mFramebuffer->bind();
    glViewport( 0, 0, mCamera->getWidth(),
        mCamera->getHeight() ); // Render on the whole framebuffer, complete from the lower left corner to the upp

    // Clear background
    glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Send view projection transforms to shader
    shader->setModelViewProjectionMatrix( glm::mat4( 1.0 ), mCamera->getTransform(), mCamera->getProjection() );

    // Enable shader
    shader->use();

    // Send light data to shader
    shader->setPointLights( pointlights );

    // Draw models
    for ( auto model : models ) {
      shader->draw( model );
    }
  }

  unsigned int getRenderTextureID()
  {
    return mRenderTexture.GLID;
  }

private:
  int mWidth;
  int mHeight;
  std::unique_ptr<FrameBuffer> mFramebuffer;
  Texture mRenderTexture;

  Camera* mCamera;
};


#endif // OPENGL_FROM_SCRATCH_GLVIEWPORT_H
