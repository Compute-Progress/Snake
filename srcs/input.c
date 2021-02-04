#include "snake.h"

void input(Context *ctx)
{
	SDL_Event		event;
	const Uint8		*keyboard;
	int 			dir;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);

	}

	dir = 0;
	ctx->input = 0;
	keyboard = SDL_GetKeyboardState(NULL);

	dir = (keyboard[SDL_SCANCODE_SPACE] != 0) ? (PAUSE) : (1);
	dir = (keyboard[SDL_SCANCODE_R]  	!= 0) ? (RESET) : (1);
	dir = (keyboard[SDL_SCANCODE_LEFT]  != 0) ? (LEFT) 	: (1);
	dir = (keyboard[SDL_SCANCODE_RIGHT] != 0) ? (RIGHT) : (1);
	dir = (keyboard[SDL_SCANCODE_UP]    != 0) ? (UP) 	: (1);
	dir = (keyboard[SDL_SCANCODE_DOWN]  != 0) ? (DOWN) 	: (1);

	ctx->input &= dir;
	
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	//ctx->snake->dir = SDL_GameControllerGetButton(ctx->controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
}