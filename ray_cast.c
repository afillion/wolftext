#include "wolf.h"

#include <stdio.h>

void	texel_2(t_env *e)
{
	if (e->side == 0)
		e->wall_x = e->ray_pos_y + e->d_ray * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->d_ray * e->ray_dir_x;
	e->wall_x -= floor((e->wall_x));
	e->tex_x = (int)(e->wall_x * e->tex_width);
	if (e->side == 0 && e->ray_dir_x > 0)
		e->tex_x = e->tex_width - e->tex_x - 1;
	if (e->side == 1 && e->ray_dir_y < 0)
		e->tex_x = e->tex_width - e->tex_x - 1;
}

void	ray_cast(t_env *e)
{
	int	pos;
	int d;

	e->x = 0;
	while (e->x < MAP_W)
	{
		e->y = 0;
		e->cam_x = 2 * e->x / MAP_W - 1;
		init_ray(e);
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
//		texel_2(e, x);
		texel(e);
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
			d = e->y * 256 - MAP_H * 128 + e->height_line * 128;
			e->tex_y = ((d * TEX_HEIGHT) / e->height_line) / 256;
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
