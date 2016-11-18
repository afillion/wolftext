#include "wolf.h"

void	untextured_color(t_env *e)
{
	e->color = 0xFFFFFF;
	if (e->world_map[e->map_x][e->map_y] == 1)
	{
		e->color = 0xFF0000;
		e->tex_id = 1;
	}
	if (e->world_map[e->map_x][e->map_y] == 2)
		e->color = 0x00FF00;
	if (e->world_map[e->map_x][e->map_y] == 3)
		e->color = 0x0000FF;
	if (e->world_map[e->map_x][e->map_y] == 4)
		e->color = 0xFFFF00;
	if (e->world_map[e->map_x][e->map_y] == 5)
		e->color = 0xEEFF00;
	if (e->world_map[e->map_x][e->map_y] == 6)
		e->color = 0xFFEE00;
	if (e->world_map[e->map_x][e->map_y] == 7)
		e->color = 0x00FFEE;
	if (e->world_map[e->map_x][e->map_y] == 8)
		e->color = 0xEEEE00;
	if (e->world_map[e->map_x][e->map_y] == 9)
		e->color = 0xECFFBB;
	if (e->world_map[e->map_x][e->map_y] == 10)
		e->color = 0xFFFF00;
	if (e->side == 1)
		e->color = e->color / 2;
	if (e->y < e->start)
		e->color = 0x00FFFF;
	if (e->y > e->end)
		e->color = 0xFFCC99;
}

void	untextured(t_env *e)
{
	int pos;

	while (e->y < MAP_H)
	{
		e->color = 0xFFCC99;
		untextured_color(e);
		pos = (e->x * e->bpp / 8) + (e->y * e->size);
		e->data[pos] = e->color % 256;
		e->data[pos + 1] = (e->color >> 8) % 256;
		e->data[pos + 2] = (e->color >> 16) % 256;
		e->y++;
	}
}
