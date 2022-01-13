//
//  Renderer.hpp
//  OpenGL
//
//  Created by 张逸凡 on 2022/1/12.
//

#pragma once

#include <GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"

#define ASSERT(x) if(!(x)) __builtin_trap()
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLlogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLlogCall(const char* function, const char* file, int line);

class Renderer
{
public:
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib) const;
};
