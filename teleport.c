#include "wolf.h"

void	check_teleport(t_env *e)
{
	if (e->world_map[e->map_x][e->map_y] == 9)
	{
		map2(e);
		e->pos_x = 20;
		e->pos_y = 12;
	}
}
