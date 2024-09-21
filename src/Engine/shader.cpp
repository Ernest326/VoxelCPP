#include "shader.hpp"

Shader::Shader(const char* vertPath, const char* fragPath) : m_vertPath(vertPath), m_fragPath(fragPath)
{
	m_shaderID = load();
}

Shader::~Shader()
{
	glDeleteProgram(m_shaderID);
}

GLuint Shader::load()
{

	GLuint program = glCreateProgram();

	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertSourceString = file_utils::read_file(m_vertPath);
	std::string fragSourceString = file_utils::read_file(m_fragPath);

	const char* vertSource = vertSourceString.c_str();
	const char* fragSource = fragSourceString.c_str();

	glShaderSource(vertShader, 1, &vertSource, NULL);
	glShaderSource(fragShader, 1, &fragSource, NULL);

	glCompileShader(vertShader);
	glCompileShader(fragShader);

	GLint success;
	char infoLog[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {
		glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
		std::cout << "ERROR: Failed to compile vertex shader: " << m_vertPath << "\n" << infoLog << std::endl;
		glDeleteShader(vertShader);
		return 0;
	}

	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE) {

		glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
		std::cout << "ERROR: Failed to compile fragment shader: " << m_fragPath << "\n" << infoLog << std::endl;
		glDeleteShader(fragShader);
		return 0;
	}

	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	return program;
}

void Shader::enable() const
{
	glUseProgram(m_shaderID);
}

void Shader::disable() const
{
	glUseProgram(0);
}

void Shader::setMatrix4(char* location, glm::mat4 value) const
{
	glUniformMatrix4fv(glGetUniformLocation(this->m_shaderID, location), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setVector3f(char* location, glm::vec3 value) const
{
	glUniform3f(glGetUniformLocation(this->m_shaderID, location), value.x, value.y, value.z);
}

void Shader::setFloat(char* location, float value) const
{
	glUniform1f(glGetUniformLocation(this->m_shaderID, location), value);
}

void Shader::setInt(char* location, int value) const
{
	glUniform1i(glGetUniformLocation(this->m_shaderID, location), value);
}

void Shader::setBool(char* location, bool value) const
{
	glUniform1i(glGetUniformLocation(this->m_shaderID, location), value);
}