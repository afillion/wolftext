#include "wolf.h"
#include <stdio.h>

void	put_pixel_to_img(t_env *e, double x, double y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}

void	color(t_env *e, double y)
{
	t_col col;

	y = 1;
	e->color = 0xFFFFFF;
	if (e->world_map[e->map_x][e->map_y] == 1)
	{
		e->tex_id = 1;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 2)
	{
		e->tex_id = 2;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 3)
	{
		e->tex_id = 3;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 4)
	{
		e->tex_id = 4;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 5)
	{
		e->tex_id = 5;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 6)
	{
		e->tex_id = 6;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 7)
	{
		e->tex_id = 7;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 8)
	{
		e->tex_id = 8;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == 9)
	{
		e->tex_id = 9;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->world_map[e->map_x][e->map_y] == -1)
	{
		e->tex_id = 10;
		get_xpm_pixel(e, &col, e->tex_x, e->tex_y);
		put_xpm_pixel_to_image(e, &col, e->x, e->y);
	}
	if (e->side == 1)
		e->color = e->color / 2;
	if (y < e->start)
		e->color = 0x00FFFF;
	if (y > e->end)
		e->color = 0xFFCC99;
}
