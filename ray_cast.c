#include "wolf.h"
#include <stdio.h>

void	ray_cast(t_env *e)
{
	//int	pos;
	int d;
	t_col col;

	e->x = 0;
	while (e->x < MAP_W)
	{
		e->y = 0;
		e->cam_x = 2 * e->x / MAP_W - 1;
		init_ray(e);
		get_way_and_dist(e);
		dda_algo(e);
		get_start_end(e);
		texel(e);
//		while (e->y < e->start)
//		{
//			e->color = 0x00FFFF;
//			pos = (e->x * e->bpp / 8) + (e->y * e->size);
//			e->data[pos] = e->color % 256;
//			e->data[pos + 1] = (e->color >> 8) % 256;
//			e->data[pos + 2] = (e->color >> 16) % 256;
//			e->y++;
//		}

		while (e->y < e->end)
		{
			d = e->y * 256 - MAP_H * 128 + e->height_line * 128;
			e->tex_y = ((d * TEX_HEIGHT) / e->height_line) / 256;
			color(e, e->y);
			e->y++;
		}
		while (e->y < MAP_H)
		{
			e->d_wall = e->d_ray;
			e->d_player = 0;
			e->current_d = 0;
			ft_floor(e);
			e->current_d = MAP_H / (2 * e->y - MAP_H);
			e->weight = (e->current_d - e->d_player) / (e->d_wall - e->d_player);
			e->current_floor_x = e->weight * e->floor_wall_x + (1.0 - e->weight) * e->pos_x;
			e->current_floor_y = e->weight * e->floor_wall_y + (1.0 - e->weight) * e->pos_y;
			e->floor_tex_x = (int)(e->current_floor_x * TEX_WIDTH) % TEX_WIDTH;
			e->floor_tex_y = (int)(e->current_floor_y * TEX_HEIGHT) % TEX_HEIGHT;
			e->tex_id = 0;
			get_xpm_pixel(e, &col, e->floor_tex_x, e->floor_tex_y);
			put_xpm_pixel_to_image(e, &col, e->x, e->y);
			e->tex_id = 9;
			get_xpm_pixel(e, &col, e->floor_tex_x, e->floor_tex_y);
			put_xpm_pixel_to_image(e, &col, e->x, MAP_H - e->y - 1);
//			e->color = 0xFFCC99;
//			pos = (e->x * e->bpp / 8) + (e->y * e->size);
//			e->data[pos] = e->color % 256;
//			e->data[pos + 1] = (e->color >> 8) % 256;
//			e->data[pos + 2] = (e->color >> 16) % 256;
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
