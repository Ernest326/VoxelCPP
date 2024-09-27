#include "texture2d.hpp"

Texture2D::Texture2D(char* path, GLint wrap, GLint filter)
{
	this->m_path = path;
	this->m_wrap = wrap;
	this->m_filter = filter;
	this->m_antialiasing = false;

	loadTexture();
}

Texture2D::Texture2D(char* path, GLint wrap, GLint filter, GLsizei samples)
{
	this->m_path = path;
	this->m_wrap = wrap;
	this->m_filter = filter;
	this->m_antialiasing = true;
	this->m_samples = samples;
	
	loadTexture();
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_texture);
}

void Texture2D::loadTexture()
{
	unsigned int texture;
	glGenTextures(1, &texture);
	
	if (m_antialiasing) {
		glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	
	if (m_antialiasing) {
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_S, m_wrap);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_T, m_wrap);
									 
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, m_filter);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, m_filter);
	}
	else {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrap);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_filter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_filter);
	}

	int width, height, nrChannels;
	unsigned char *data = stbi_load(m_path, &width, &height, &nrChannels, STBI_rgb_alpha);

	if (data)
	{
		if (m_antialiasing) {
			glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE,  m_samples, GL_RGB, width, height, GL_TRUE);
			glGenerateMipmap(GL_TEXTURE_2D_MULTISAMPLE);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}
	else
	{
		std::cout << "ERROR: Failed to load texture:" << m_path << std::endl;
	}

	m_texture = texture;
	stbi_image_free(data);

	if (m_antialiasing) {
		glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}