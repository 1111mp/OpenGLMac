//
//  Texture.cpp
//  OpenGL
//
//  Created by 张逸凡 on 2022/1/12.
//

#include "Texture.h"

#include "stb_image/stb_image.h"

Texture::Texture(const std::string& path)
	: m_RendererID(0), m_FilePath(path), m_Width(0), m_Height(0), m_BPP(0)
{
	// 加载纹理资源
	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	// 创建纹理
	(glGenTextures(1, &m_RendererID));
	(glBindTexture(GL_TEXTURE_2D, m_RendererID));

	// 纹理环绕方式
	(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	// 纹理过滤
	(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
	(glGenerateMipmap(GL_TEXTURE_2D));

	// 解绑纹理对象
	(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);
}

Texture::~Texture()
{
	(glDeleteTextures(1, &m_RendererID));
}

void Texture::Bind(unsigned int slot) const
{
	(glActiveTexture(GL_TEXTURE0 + slot));
	(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Texture::UnBind() const
{
	(glBindTexture(GL_TEXTURE_2D, 0));
}
