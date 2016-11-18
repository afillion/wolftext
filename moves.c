#include "wolf.h"

void	forward(t_env *e)
{
	if (e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)]
			[(int)(e->pos_y)] <= 0)
		e->pos_x += e->dir_x * e->move_speed;
	if (e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y + e->dir_y * e->move_speed)] <= 0)
		e->pos_y += e->dir_y * e->move_speed;
}

void	backward(t_env *e)
{
	if (e->world_map[(int)(e->pos_x - e->dir_x * e->move_speed)]
			[(int)e->pos_y] <= 0)
		e->pos_x -= e->dir_x * e->move_speed;
	if (e->world_map[(int)e->pos_x]
			[(int)(e->pos_y - e->dir_y * e->move_speed)] <= 0)
		e->pos_y -= e->dir_y * e->move_speed;
}

void	left(t_env *e)
{
	if (e->world_map[(int)(e->pos_x - e->dir_y * e->move_speed)]
			[(int)(e->pos_y)] <= 0)
		e->pos_x -= e->dir_y * e->move_speed;
	if (e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y + e->dir_x * e->move_speed)] <= 0)
		e->pos_y += e->dir_x * e->move_speed;
}

void	right(t_env *e)
{
	if (e->world_map[(int)(e->pos_x + e->dir_y * e->move_speed)]
			[(int)(e->pos_y)] <= 0)
		e->pos_x += e->dir_y * e->move_speed;
	if (e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y - e->dir_x * e->move_speed)] <= 0)
		e->pos_y -= e->dir_x * e->move_speed;
}

void	run(t_env *e)
{
	if (e->run == 1)
	{
		if (e->textured == 0)
			e->move_speed = 0.70;
		else
			e->move_speed = 0.85;
	}
	else
	{
		if (e->textured == 0)
			e->move_speed = 0.15;
		else
			e->move_speed = 0.30;
	}
}
