//
//  IndexBuffer.cpp
//  OpenGL
//
//  Created by 张逸凡 on 2022/1/12.
//

#include "IndexBuffer.h"

#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
: m_Count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	
	(glGenBuffers(1, &m_RendererID)); // generate memory in Video RAM
	(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	/* glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数 */
	(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
	(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::UnBind() const
{
	(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
