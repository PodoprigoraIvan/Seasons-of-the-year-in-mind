#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Drawable.h"
#include "GLM_headers.h"
#include "Shader.h"
#include "VAO_generator.h"

class OneColorFigure : public Drawable {
private:
	int drawType;
	glm::vec3 color;
	Shader* shader_ptr;
	VAO_generator VAO_gen;
public:
	OneColorFigure(Shader * shader_ptr, float * vertices, int verticesSize, unsigned int * indices, int indicesSize, int drawType, glm::vec3 color, float x = 0, float y = 0, float z = 0);
	void draw(const glm::mat4& view, const glm::mat4& projection);
};