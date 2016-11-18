#include "wolf.h"

void	init_key(t_env *e)
{
	e->forward = 0;
	e->left = 0;
	e->right = 0;
	e->backward = 0;
	e->up = 0;
	e->lrotate = 0;
	e->rrotate = 0;
	e->down = 0;
}

void	press(int keycode, t_env *e)
{
	if (keycode == FORWARD)
		e->forward = 1;
	else if (keycode == BACKWARD)
		e->backward = 1;
	else if (keycode == LEFT)
		e->left = 1;
	else if (keycode == RIGHT)
		e->right = 1;
	else if (keycode == DOWN)
		e->down = 1;
	else if (keycode == UP)
		e->up = 1;
	else if (keycode == RROTATE)
		e->rrotate = 1;
	else if (keycode == LROTATE)
		e->lrotate = 1;
}

int		key_press(int keycode, t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (keycode == 53)
	{
		free(e);
		exit(0);
	}
	if (keycode == 18)
		e->textured = 1;
	if (keycode == 19)
		e->textured = 0;
	if (keycode == 12)
		e->run = 1;
	press(keycode, e);
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == 12)
		e->run = 0;
	if (keycode == FORWARD)
		e->forward = 0;
	else if (keycode == BACKWARD)
		e->backward = 0;
	else if (keycode == LEFT)
		e->left = 0;
	else if (keycode == RIGHT)
		e->right = 0;
	else if (keycode == UP)
		e->up = 0;
	else if (keycode == DOWN)
		e->down = 0;
	else if (keycode == LROTATE)
		e->lrotate = 0;
	else if (keycode == RROTATE)
		e->rrotate = 0;
	return (0);
}
