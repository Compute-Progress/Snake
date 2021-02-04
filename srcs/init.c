#include "snake.h"

void reset_game(Context *ctx)
{
	snake_node *head;
	snake_node *tmp;
	int i;

	i = 0;
	ctx->game = 1;
	ctx->score = 0;
	ctx->snake->dir = RIGHT;
	ctx->snake->old_dir = RIGHT;
	head = ctx->snake->head;
	ctx->snake->head = head;
	while (i < SNAKE_INITIAL)
	{
		head->next->x = 9;
		head->next->y = 10;
		head = head->next;
		i++;
	}
	ctx->snake->tail = head;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	parse_map(ctx);
}

void init_ctx(Context *ctx)
{
	snake_node *head;
	int i;

	i = 0;
	ctx->game = 1;
	ctx->score = 0;
	ctx->snake->dir = RIGHT;
	ctx->snake->old_dir = RIGHT;
	parse_map(ctx);
	if (!ctx->snake)
		ctx->snake = calloc(1, sizeof(*ctx->snake));
	head = new_node(10, 10);

	ctx->snake->head = head;
	while (i < SNAKE_INITIAL)
	{
		head->next = new_node(9, 10);
		head = head->next;
		i++;
	}
	ctx->snake->tail = head;
	TTF_Init();

	ctx->font = TTF_OpenFont(strjoin(ASSETS_PATH, "Pixel_Font.ttf"), 30);
}

Context *get_context()
{
	static Context ctx;

	if (ctx.snake == NULL)
		init_ctx(&ctx);

	return &ctx;
}