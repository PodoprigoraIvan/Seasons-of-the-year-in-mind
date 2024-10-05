#include "VAO_generator.h"
#include <iostream>
VAO_generator::VAO_generator(VAO_type type, int draw_mode, float* data, int dataSize, unsigned int* indices, int indicesSize) {
	if (draw_mode != GL_STATIC_DRAW && draw_mode != GL_DYNAMIC_DRAW && draw_mode != GL_STREAM_DRAW) {
		std::cout << "Error in VAO_generator constructor: draw_mode must be GL_STATIC_DRAW or GL_DYNAMIC_DRAW or GL_STREAM_DRAW\n";
	}
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, draw_mode);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, draw_mode);

	if (type == VERTEX){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}
	if (type == VERTEX_COLOR) {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
	if (type == VERTEX_TEXTURE) {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
}

VAO_generator::~VAO_generator() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}