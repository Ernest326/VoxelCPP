#pragma once
#include <iostream>
#include <stb_image.h>
#include <glad/glad.h>

class Texture2D
{
private:
	char* m_path;
	GLint m_wrap;
	GLint m_filter;
	GLuint m_texture;
	bool m_antialiasing;
	GLsizei m_samples;

public:
	Texture2D(char* path, GLint wrap, GLint filter);
	Texture2D(char* path, GLint wrap, GLint filter, GLsizei samples);
	~Texture2D();

	void bind() { glBindTexture(GL_TEXTURE_2D, m_texture); }
	void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
	
	GLuint getTexture() { return m_texture; }

private:
	void loadTexture();

};