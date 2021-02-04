#include "snake.h"

typedef void(*game_func)(Context *ctx);

void main_loop(Context *ctx);
void game_over(Context *ctx);
void pause(Context *ctx);


int main()
{
	SDLX_Display 	*display;
	Context 		*context;
	game_func		loops[3];
	
	display = SDLX_GetDisplay();
	context = get_context();

	loops[0] = &pause;
	loops[1] = &main_loop;
	loops[2] = &game_over;

	SDL_Log("Initialized\n");
	while (1)
	{
		input(context);
		loops[context->game];
		render_game(context);
		SDLX_RenderLoop();
	}
}