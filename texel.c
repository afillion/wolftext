#include "wolf.h"

void	put_xpm_pixel_to_image(t_env *e, t_col *col, int x, int y)
{
	e->data[y * e->size + x * (e->bpp / 8)] = col->b;
	e->data[y * e->size + x * (e->bpp / 8) + 1] = col->g;
	e->data[y * e->size + x * (e->bpp / 8) + 2] = col->r;
}

void	get_xpm_pixel(t_env *e, t_col *col, int x, int y)
{
//	if (x > 64)
//		x = x % 64;
//	if (y > 64)
//		y = y % 64;
	if (e->tex_id == 9)
	{
		if (x > 900)
			x %= 900;
		if (y > 90)
			y %= 90;
	}
	col->b = e->tex_tab[e->tex_id].data[(y * e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8 * x)];
	col->g = e->tex_tab[e->tex_id].data[(y * e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8 * x) + 1];
	col->r = e->tex_tab[e->tex_id].data[(y * e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8 * x) + 2];
}

int		load_texture(t_env *e, t_tex *image, char *file)
{
	int	w;
	int	h;

	w = TEX_WIDTH;
	h = TEX_HEIGHT;
	if (e->tex_id == 9)
	{
		h = 900;
		w = 90;
	}
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &w, &h)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp, &image->size, &image->endian);
	return (0);
}

int		tex_init(t_env *e)
{
	load_texture(e, &e->tex_tab[0], "./Texture/grass.xpm");
	load_texture(e, &e->tex_tab[1], "./Texture/colorstone.xpm");
	load_texture(e, &e->tex_tab[2], "./Texture/bluestone.xpm");
	load_texture(e, &e->tex_tab[3], "./Texture/eagle.xpm");
	load_texture(e, &e->tex_tab[4], "./Texture/greystone.xpm");
	load_texture(e, &e->tex_tab[5], "./Texture/xpm_texts/trees.xpm");
	load_texture(e, &e->tex_tab[6], "./Texture/redbrick.xpm");
	load_texture(e, &e->tex_tab[7], "./Texture/wallbrick.xpm");
	load_texture(e, &e->tex_tab[8], "./Texture/wood.xpm");
	load_texture(e, &e->tex_tab[9], "./Texture/xpm_texts/sky.xpm");
	load_texture(e, &e->tex_tab[10], "./Texture/xpm_texts/housedoor.xpm");
	return (0);
}

void	texel(t_env *e)
{
	if (e->side == 0)
		e->wall_x = e->ray_pos_y + e->d_ray * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->d_ray * e->ray_dir_x;
	e->wall_x -= floor((e->wall_x));
	e->tex_x = (int)(e->wall_x * 64);
	if (e->side == 0 && e->ray_dir_x > 0)
		e->tex_x = 64 - e->tex_x - 1;
	if (e->side == 1 && e->ray_dir_y < 0)
		e->tex_x = 64 - e->tex_x - 1;
}
