#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class VAO_generator {
public:
	enum VAO_type {
		VERTEX,
		VERTEX_COLOR,
		VERTEX_TEXTURE
	};

	VAO_generator(VAO_type type, int draw_mode, float * data, int dataSize, unsigned int * indices, int indicesSize);

	~VAO_generator();

	unsigned int getVAO() {
		return VAO;
	}
	unsigned int getVBO() {
		return VBO;
	}
	unsigned int getEBO() {
		return VAO;
	}

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
};