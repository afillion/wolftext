#include "wolf.h"

void	init_ray(t_env *e)
{
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;
	e->ray_dir_x = e->dir_x + (e->plane_x * e->cam_x);
	e->ray_dir_y = e->dir_y + (e->plane_y * e->cam_x);
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->x_a = sqrt(1 + (e->ray_dir_y * e->ray_dir_y)
			/ (e->ray_dir_x * e->ray_dir_x));
	e->y_a = sqrt(1 + (e->ray_dir_x * e->ray_dir_x)
			/ (e->ray_dir_y * e->ray_dir_y));
	e->hit = 0;
	if (e->textured == 0)
		e->move_speed = 0.15;
	else
		e->move_speed = 0.30;
	if (e->textured == 0)
		e->rot_speed = 0.14;
	else
		e->rot_speed = 0.21;
}

void	init_struct(t_env *e)
{
	e->teleport = 0;
	e->textured = 1;
	e->run = 0;
	e->pos_x = 20;
	e->pos_y = 12;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->time = 0;
	e->old_time = 0;
	e->line = 0;
	e->col = 0;
}
