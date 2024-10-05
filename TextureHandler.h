#pragma once

#include <string>

using namespace std;

class TextureHandler {
public:
	/// <summary>
	/// TextureHandler constructor
	/// </summary>
	/// <param name="path">Path to image file</param>
	/// <param name="format">GL_RGB or GL_RGBA (type of data stored in file)</param>
	/// <param name="flip_vertically">default vaule = true, flip loaded image or not</param>
	TextureHandler(string path, GLenum format, bool flip_vertically = true);
	void bind();
	~TextureHandler();
private:
	unsigned int textureID;
};