#include "wolf.h"

void	ray_cast(t_env *e)
{
	check_teleport(e);
	e->x = 0;
	while (e->x < MAP_W)
	{
		e->y = 0;
		e->cam_x = 2 * e->x / MAP_W - 1;
		init_ray(e);
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
		if (e->textured == 1)
			textured(e);
		else if (e->textured == 0)
			untextured(e);
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
