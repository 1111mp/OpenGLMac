//
//  VertexBuffer.hpp
//  OpenGL
//
//  Created by 张逸凡 on 2022/1/12.
//

#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererID;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};
