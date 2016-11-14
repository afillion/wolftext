#include "wolf.h"
#include <stdio.h>

void	texel(t_env *e)
{
//	int	a = (double) 8;

	if (e->side == 0)
		e->wall_x = e->ray_pos_y + e->d_ray * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->d_ray * e->ray_dir_x;
	e->wall_x -= floor((e->wall_x));
//	printf("e->wall_x:%f\n", e->wall_x);
	e->tex_x = (int)(e->wall_x * 64);
	if (e->side == 0 && e->ray_dir_x > 0)
		e->tex_x = e->tex_width - e->tex_x - 1;
	if (e->side == 1 && e->ray_dir_y < 0)
		e->tex_x = e->tex_width - e->tex_x - 1;
//printf("e->tex_x:%d\n", e->tex_x);
}
