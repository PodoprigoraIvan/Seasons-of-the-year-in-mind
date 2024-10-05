#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "stb_image.h"
#include "TextureHandler.h"

TextureHandler::TextureHandler(string path, GLenum format, bool flip_vertically) {
    GLint previousTexture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &previousTexture);
    stbi_set_flip_vertically_on_load(flip_vertically);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char* textureData = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (textureData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture, PATH: " << path << std::endl;
    }
    stbi_image_free(textureData);
    glBindTexture(GL_TEXTURE_2D, previousTexture);
}

void TextureHandler::bind() {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

TextureHandler::~TextureHandler() {
    glDeleteTextures(1, &textureID);
}
