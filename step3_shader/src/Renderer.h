#pragma once

#include <glad/glad.h>
#include <iostream>
#include "VertexArray.h"
#include "VertexBuffer.h"
#define ASSERT(function) if(!(function)) __debugbreak();
#define GLCall(function) GLClearError();\
		function;\
		ASSERT(GLLogCall(#function,__FILE__,__LINE__))


void GLClearError();
bool GLLogCall(const char* function,const char* file,int line);


class Renderer
{ 
public:
	void clear(float r, float g, float b, float a)const;
	void draw(const VertexArray& va,const VertexBuffer& vb, const VertexArrayLayout& layout)const;
};

