//
//  VertexBuffer.cpp
//  OpenGL
//
//  Created by 张逸凡 on 2022/1/12.
//

#include "VertexBuffer.h"

#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	(glGenBuffers(1, &m_RendererID)); // generate memory in Video RAM
	(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	/* glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数 */
	(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
	(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::UnBind() const
{
	(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
