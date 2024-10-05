#pragma once

#include "GLM_headers.h"

class Drawable {
public:
	float xPos;
	float yPos;
	float zPos;

	Drawable(float x = 0, float y = 0, float z = 0) : xPos(x), yPos(y), zPos(z) {}
	virtual void draw(const glm::mat4& view, const glm::mat4& projection) = 0;
	~Drawable() {};
};