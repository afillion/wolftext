#include "wolf.h"

void	ray_cast(t_env *e)
{
	int	pos;

	e->x = 0;
	while (e->x < MAP_W)
	{
		e->y = 0;
		e->cam_x = 2 * e->x / MAP_W - 1;
		init_ray(e);
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
		while (e->y < e->start)
		{
			e->color = 0x00FFFF;
			pos = (e->x * e->bpp / 8) + (e->y * e->size);
			e->data[pos] = e->color % 256;
			e->data[pos + 1] = (e->color >> 8) % 256;
			e->data[pos + 2] = (e->color >> 16) % 256;
			e->y++;
		}
		while (e->y < e->end)
		{
			color(e, e->y);
			//put_pixel_to_img(e, e->x, e->y);
			e->y++;
		}
		while (e->y < MAP_H)
		{
			e->color = 0xFFCC99;
			pos = (e->x * e->bpp / 8) + (e->y * e->size);
			e->data[pos] = e->color % 256;
			e->data[pos + 1] = (e->color >> 8) % 256;
			e->data[pos + 2] = (e->color >> 16) % 256;
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
