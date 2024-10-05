#include "OneColorFigure.h"

OneColorFigure::OneColorFigure(Shader* shader_ptr, float* vertices, int verticesSize, unsigned int* indices, int indicesSize, int drawType, glm::vec3 color, float x, float y, float z)
	: Drawable(x, y, z),
	drawType(drawType),
	color(color),
	shader_ptr(shader_ptr),
	VAO_gen(VAO_generator::VERTEX, GL_STATIC_DRAW, vertices, verticesSize, indices, indicesSize)
{}

void OneColorFigure::draw(const glm::mat4& view, const glm::mat4& projection) {
	shader_ptr->use();
	glBindVertexArray(VAO_gen.getVAO());
	glm::mat4 model = glm::translate(glm::mat4(1.0), glm::vec3(xPos, yPos, zPos));
	shader_ptr->setMat4("model", model);
	shader_ptr->setMat4("view", view);
	shader_ptr->setMat4("projection", projection);
	shader_ptr->setVec3("aColor", color);
	glDrawElements(drawType, 6, GL_UNSIGNED_INT, 0);
}