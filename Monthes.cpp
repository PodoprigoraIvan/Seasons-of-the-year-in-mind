#include "Monthes.h"

Monthes::Monthes() : shader("./shaders/SimpleColor.vert", "./shaders/SimpleColor.frag") {
    unsigned int indices[] = {
        0, 1, 3, // first triangle 0, 1, 3
        1, 2, 3  // second triangle
    };

    unsigned int indicesBorder[] = {
        0, 1, 2, 3,
    };

    glm::vec3 fallColor(0.701, 0.396, 0.122);
    glm::vec3 decemberColor(0.0, 0.99, 0.99);
    glm::vec3 winterColor(0.0, 0.482, 0.99);
    glm::vec3 springColor(1.0, 0.874, 0.0);
    glm::vec3 summerColor(1.0, 0.718, 0.11);

    glm::vec3 borderColor(0.2, 0.2, 0.2);

    auto addMonth = [&](float* vertices, glm::vec3 color) {
        OneColorFigure * month = new OneColorFigure(&shader, vertices, sizeof(float)*12, indices, sizeof(indices), GL_TRIANGLES, color);
        OneColorFigure * border = new OneColorFigure(&shader, vertices, sizeof(float) * 12, indicesBorder, sizeof(indicesBorder), GL_LINE_LOOP, borderColor);
        monthDrawables.push_back(month);
        monthDrawables.push_back(border);
    };

    float septemberVertices[] = { 7.0, 0.0, -2.0, 6.0, 0.0, -4.0, 9.0, 0.0, -7.0, 11.0, 0.0, -3.0 };
    float octoberVertices[] = { 7.0, 0.0, 2.0, 7.0, 0.0, -2.0, 11.0, 0.0, -3.0, 11.0, 0.0, 3.0 };
    float novemberVertices[] = { 7.0, 0.0, 2.0, 6.0, 0.0, 4.0, 9.0, 0.0, 7.0, 11.0, 0.0, 3.0 };

    float marchVertices[] = { -7.0, 0.0, -2.0, -6.0, 0.0, -4.0, -9.0, 0.0, -7.0, -11.0, 0.0, -3.0 };
    float aprilVertices[] = { -7.0, 0.0, 2.0, -7.0, 0.0, -2.0, -11.0, 0.0, -3.0, -11.0, 0.0, 3.0 };
    float mayVertices[] = { -7.0, 0.0, 2.0, -6.0, 0.0, 4.0, -9.0, 0.0, 7.0, -11.0, 0.0, 3.0 };

    float decemberVertices[] = { 2.0, 0.0, -6.0, 6.0, 0.0, -4.0, 9.0, 0.0, -7.0, 3.0, 0.0, -10.0 };
    float januaryVertices[] = { -2.0, 0.0, -6.0, 2.0, 0.0, -6.0, 3.0, 0.0, -10.0, -3.0, 0.0, -10.0 };
    float februaryVertices[] = { -2.0, 0.0, -6.0, -6.0, 0.0, -4.0, -9.0, 0.0, -7.0, -3.0, 0.0, -10.0 };

    float juneVertices[] = { 2.0, 0.0, 6.0, 6.0, 0.0, 4.0, 9.0, 0.0, 7.0, 3.0, 0.0, 10.0 };
    float julyVertices[] = { -2.0, 0.0, 6.0, 2.0, 0.0, 6.0, 3.0, 0.0, 10.0, -3.0, 0.0, 10.0 };
    float augustVertices[] = { -2.0, 0.0, 6.0, -6.0, 0.0, 4.0, -9.0, 0.0, 7.0, -3.0, 0.0, 10.0 };

    addMonth(septemberVertices, fallColor);
    addMonth(octoberVertices, fallColor);
    addMonth(novemberVertices, fallColor);
    addMonth(marchVertices, springColor);
    addMonth(aprilVertices, springColor);
    addMonth(mayVertices, springColor);
    addMonth(decemberVertices, decemberColor);
    addMonth(januaryVertices, winterColor);
    addMonth(februaryVertices, winterColor);
    addMonth(juneVertices, summerColor);
    addMonth(julyVertices, summerColor);
    addMonth(augustVertices, summerColor);
}

void Monthes::draw(const glm::mat4& view, const glm::mat4& projection) {
    glLineWidth(2.0);
    for (auto monthDrawable : monthDrawables) {
        monthDrawable->draw(view, projection);
    }
}

Monthes::~Monthes() {
    for (auto monthDrawable : monthDrawables) {
        delete monthDrawable;
    }
}