//
// Created by vector on 24/03/08.
//

#ifndef DEV_MATERIAL_H
#define DEV_MATERIAL_H

#include <memory>
#include <fbxsdk.h>
#include "Texture.h"
#include "Shader.h"

class Material {
public:
  Material( const char* name );

  void CreateFromFbxSurfaceMaterial( FbxSurfaceMaterial* material );

  inline const char* GetName() {
    return mName;
  }

  inline std::shared_ptr<Texture>* GetTextures() {
    return mTextures;
  }

  inline std::shared_ptr<PhongShader> GetShader() {
    return mShader;
  }

protected:
  const char* mName;
  std::shared_ptr<PhongShader> mShader;
  std::shared_ptr<Texture> mTextures[TEXTURETYPE_NUM_ITEMS];
};


#endif // DEV_MATERIAL_H
