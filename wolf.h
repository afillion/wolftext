#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# define PI 3.14159265359
# define MAP_W 1000
# define MAP_H 800
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define FORWARD 13
# define LEFT 0
# define BACKWARD 1
# define RIGHT 2
# define UP 126
# define LROTATE 123
# define DOWN 125
# define RROTATE 124

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_col;

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_tex;

typedef struct	s_env
{
	int			teleport;
	int			run;
	int			textured;
	double		x;
	double		y;
	struct s_texture	tex_tab[11];
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		cam_x;
	double		cam_y;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		d_x;
	double		d_y;
	double		x_a;
	double		y_a;
	double		d_ray;
	int			way_x;
	int			way_y;
	int			hit;
	int			side;
	int			height_line;
	int			start;
	int			end;
	int			color;
	int			bpp;
	int			size;
	int			endian;
	double		old_dir_x;
	double		old_plane_x;
	double		move_speed;
	double		rot_speed;
	double		h_cam;
	int			line;
	int			col;
	int			world_map[22][22];
	char		*filename;
	int			forward;
	int			left;
	int			right;
	int			backward;
	int			up;
	int			lrotate;
	int			rrotate;
	int			down;
	double		updown;
	int			buffer[MAP_H][MAP_W];
	int			lenght;
	int			width;
	int			tex_x;
	int			tex_y;
	double		wall_x;
	int			tex_id;
	double		floor_wall_x;
	double		floor_wall_y;
	double		weight;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
	double		d_wall;
	double		d_player;
	double		current_d;
}				t_env;

void			ray_cast(t_env *e);
void			put_pixel_to_img(t_env *e, double x, double y);
void			parse_map(t_env *e);
int				count_word(const char *s, char c);
int				key_press(int keycode, t_env *e);
int				key_release(int keycode, t_env *e);
void			init_key(t_env *e);
int				key_hook(t_env *e);
void			forward(t_env *e);
void			backward(t_env *e);
void			left(t_env *e);
void			right(t_env *e);
void			right_rotate(t_env *e);
void			left_rotate(t_env *e);
void			updown_view(t_env *e);
void			get_way_and_dist(t_env *e);
void			dda_algo(t_env *e);
void			get_start_end(t_env *e);
void			init_ray(t_env *e);
void			init_struct(t_env *e);
void			color(t_env *e, double y);
void			texel(t_env *e);
void			put_xpm_pixel_to_image(t_env *e, t_col *col, int x, int y);
void			get_xpm_pixel(t_env *e, t_col *col, int x, int y);
int				load_texture(t_env *e, t_tex *image, char *file);
int				tex_init(t_env *e);
void			ft_floor(t_env *e);
void			map(t_env *e);
void			textured(t_env *e);
void			untextured(t_env *e);
void			shadow_effect(t_env *e, t_col *col);
void			map(t_env *e);
void			map2(t_env *e);
void			check_teleport(t_env *e);
void			run(t_env *e);

#endif
