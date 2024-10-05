#pragma once
#include "OneColorFigure.h"
#include "GLM_headers.h"
#include <vector>
#include <iostream>

struct Monthes {
    std::vector<OneColorFigure*> monthDrawables;
    Shader shader;
    Monthes();
    void draw(const glm::mat4& view, const glm::mat4& projection);
    ~Monthes();
};