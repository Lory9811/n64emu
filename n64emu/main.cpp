#include "InterpreterCPU.h"
#include "N64.h"

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <cstdio>


int main(int argc, char** argv) {
	InterpreterCPU::Init();
	N64 n64 = N64();

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	printf("Display resolution: %dx%d\n", displayMode.w, displayMode.h);
	SDL_Window* window = SDL_CreateWindow("n64 Emulator", 
										  displayMode.w / 2 - 640 / 2, displayMode.h / 2 - 480 / 2,
										  640, 480,
										  SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);
	glewInit();

	glClearColor(0, 0, 1, 1);

	bool quit = false;
	while (!quit) {
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			n64.Update();
		}
		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}