#include "wolf.h"

void	shadow_effect(t_env *e, t_col *col)
{
	if (e->side == 1 || (e->side == 0 && e->ray_dir_x >= 0))
	{
		if (e->side == 0)
		{
			col->b = (int)(col->b / 2.5);
			col->g = (int)(col->g / 2.5);
			col->r = (int)(col->r / 2.5);
		}
		else if (e->side == 1 && e->ray_dir_y >= 0)
		{
			col->b = (int)(col->b / 2.10);
			col->g = (int)(col->g / 2.10);
			col->r = (int)(col->r / 2.10);
		}
		else
		{
			col->b = (int)(col->b / 1.25);
			col->g = (int)(col->g / 1.25);
			col->r = (int)(col->r / 1.25);
		}
	}
}
