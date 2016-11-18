#include "wolf.h"

void	textured(t_env *e)
{
	int	d;
	t_col col;

	d = 0;
	texel(e);
	while (e->y < e->end)
	{
		d = e->y * 256 - MAP_H * 128 + e->height_line * 128;
		e->tex_y = ((d * TEX_HEIGHT) / e->height_line) / 256;
		if (e->world_map[e->map_x][e->map_y] == -1)
			e->tex_id = 10;
		else
			e->tex_id = e->world_map[e->map_x][e->map_y];
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		shadow_effect(e, &col);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
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
		e->tex_id = 8;
		get_xpm_pixel(e, &col, e->floor_tex_x, e->floor_tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, MAP_H - e->y - 1);
		e->y++;
	}
}
