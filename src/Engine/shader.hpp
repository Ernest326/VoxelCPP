#pragma once
#include <iostream>
#include <glad/glad.h>
#include <vector>
#include <string>
#include "file_utils.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader {

private:
    GLuint m_shaderID;
    const char* m_vertPath, *m_fragPath;

public:
    Shader(const char* vertPath, const char* fragPath);
    Shader() {};
    ~Shader();

    void enable() const;
    void disable() const;

    GLuint shaderID() { return m_shaderID; }

private:
    GLuint load();

public:
    void setMatrix4(char* location, glm::mat4 value) const;
    void setVector3f(char* locatiuon, glm::vec3 value) const;
    void setFloat(char* location, float value) const;
    void setInt(char* location, int value) const;
    void setBool(char* location, bool value) const;

};