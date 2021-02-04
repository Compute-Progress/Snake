#include "snake.h"

snake_node *new_node(int x, int y)
{
	snake_node *new;

	new = calloc(1, sizeof(snake_node));

	new->x = x;
	new->y = y;

	return new;
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_bits(int n, int bits)
{
	for (int i = bits; i > 0; i++)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

void generate_point(Context *ctx)
{
	int x;
	int y;
	x = rand()  % (BOARD_W - 1);
	y = rand()  % (BOARD_H - 1);
	while (ctx->map[y][x] != ' ')
	{
		x = rand()  % (BOARD_W - 1);
		y = rand()  % (BOARD_H - 1);
	}
	ctx->map[y][x] = 'X';
}

char	*strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	
	len = SDL_strlen(s1) + SDL_strlen(s2) + 1;
	if (!(str = SDL_malloc(len)))
		return (NULL);
		
	str = SDL_strlcpy(str, s1, len);

	return (SDL_strlcat(str, s2, len));
}