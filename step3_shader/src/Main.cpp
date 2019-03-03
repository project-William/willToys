﻿#include "Window.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
int main() {
	{
		Window window("william", 1200, 800);
		Renderer render;
		Shader shader("res/shader.txt");

		float vertices[] = {
			-0.5f,-0.5f,0.0f,
			 0.5f,-0.5f,0.0f,
			 0.0f, 0.5f,0.0f
		};

		VertexBuffer vb(sizeof(vertices),vertices);
		VertexArray va;
		VertexArrayLayout layout;
		layout.push<float>(3);
		va.verAttribPtr(vb, layout);

		while (!window.closed()) {
			//renderint the background
			render.clear(0.2f, 0.4f, 1.0f, 1.0f);
			//bind vertex array object
			va.bind();
			//use program
			shader.bind();
			//draw traingle
			render.draw(va, vb, layout);
			//swap buffers and poll events
			window.update();
		}
		
	}
	glfwTerminate();

	return 0;
}
