#include "wolf.h"

void	put_xpm_pixel_to_image(t_env *e, t_col *col, int x, int y)
{
	e->data[y * e->size + x * (e->bpp / 8)] = col->b;
	e->data[y * e->size + x * (e->bpp / 8) + 1] = col->g;
	e->data[y * e->size + x * (e->bpp / 8) + 2] = col->r;
}

void	get_xpm_pixel(t_env *e, t_col *col, int x, int y)
{
	if (x > 64)
		x = x % 64;
	if (y > 64)
		y = y % 64;
	col->b = e->tex_tab[e->tex_id].data[(y * e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8 * x)];
	col->g = e->tex_tab[e->tex_id].data[(y * e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8 * x) + 1];
	col->r = e->tex_tab[e->tex_id].data[(y * e->tex_tab[e->tex_id].size
			+ e->tex_tab[e->tex_id].bpp / 8 * x) + 2];
}

int		load_texture(t_env *e, t_tex * image, char *file)
{
	int	w;
	int	h;

	w = TEX_WIDTH;
	h = TEX_HEIGHT;
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &w, &h)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp, &image->size, &image->endian);
	return (0);
}

int		tex_init(t_env *e)
{
	load_texture(e, &e->tex_tab[0], "./Texture/barrel.xpm");
	load_texture(e, &e->tex_tab[1], "./Texture/colorstone.xpm");
	load_texture(e, &e->tex_tab[2], "./Texture/bluestone.xpm");
	load_texture(e, &e->tex_tab[3], "./Texture/eagle.xpm");
	load_texture(e, &e->tex_tab[4], "./Texture/greystone.xpm");
	return (0);
}
