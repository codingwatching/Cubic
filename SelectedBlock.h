#pragma once
#include <GL/glew.h>

class Game;

class SelectedBlock
{
public:
	void init(Game* game);
	void renderPost();

private:
	const static int bufferSize = 24;

	GLuint vao;
	GLuint buffer;
	GLuint texture;

	Game* game;
};

