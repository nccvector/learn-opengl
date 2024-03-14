//
// Created by vector on 24/02/19.
//

#include "common.h"

// Image read write implementations
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Global texture
namespace global {

std::vector<Texture*> textures = {};

}