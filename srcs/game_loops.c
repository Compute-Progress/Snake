#include "snake.h"

void pause(Context *ctx)
{
	if (ctx->input & PAUSE)
	{
		ctx->game = 1;
		return ;
	}
}

void game_over(Context *ctx)
{
	if (ctx->input & RESET)
	{
		ctx->game = 1;
		return ;
	}

}

void main_loop(Context *ctx)
{
	move_snake
}