/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:36 by bmartin           #+#    #+#             */
/*   Updated: 2023/10/03 10:44:29 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE
# define CUBE

//////Libraries
# include "../MLX42/include/GLFW/glfw3.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>

//Variable
#define IMG_PIXEL_SIZE 64
#define WIDTH 2048
#define HEIGHT 2048

//message erreur
# define E_CHAR_INVALID "Error\nFound Invalid Character\n"
# define E_MAP_TOO_WIDTH "Error\nMap Too Wide (Max 40)\n"
# define E_MAP_TOO_HEIGTH "Error\nMap Too High (max 21)\n"
# define E_MAP_BORDER "Error\nMap Border Missing\n"
# define E_FILE_NAME "Error\nFile Is Invalid\n"
# define E_FLOODFILL "Error\nFloodfill Is Invalid\n"
# define E_ARGS_NUM "Error\nArgument Number Is Wrong\n"
# define E_COLORS "Error\nColors Is Invalid\n"

// colors
# define BCK "\x1B[30m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLE "\x1B[34m"
# define MAG "\x1B[35m"
# define CYA "\x1B[36m"
# define WHT "\x1B[37m"

//debug
# define DEBUG 1
typedef struct s_data
{
	mlx_t			*mlx;
	int				height;
	int				width;
	int				height_pixel;
	int				width_pixel;
	char			**map;

	mlx_texture_t *wall;
	mlx_texture_t *grass;
	mlx_texture_t *penguin;

	mlx_image_t *wall_img;
	mlx_image_t *grass_img;
	mlx_image_t *penguin_img;
}					t_data;

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceiling;
	char		**map;
	int			map_height;
	int			map_width;

}					t_map;

typedef struct s_player
{
	int				x;
	int				y;
	char			orientation;

}				t_player;

//function

// PARSING

//a_supp
void	f_print_tab(char **cou);
void	f_print_map(t_map *data_map);
void	f_pri_map(char **map);

//check_arg
void	f_error(char *msg);
int		f_check_cub(char *str);
void	f_check_arg(int argc, char **argv);
void	f_print_player(t_player *play);
void	f_pars_file(int ac, char **av, t_map *map);

//utils
void	*f_freenull(void *str);
char	*f_join_and_free(char *src, char *add);
t_map	*f_init_map(void);
bool	f_its_here(char *src, char *search);
char	*f_pars_direction(char *line, char *dir);
int		get_rgba(int r, int g, int b, int a);
bool	f_is_digit(char *str);
int		f_number(char *str);
int		f_return_colors(char *line, char *dir);
int		*f_tab_color(char *line);
char	*f_pars_colors(char *line, char *dir);
bool	f_is_good_data(t_map *map);
t_player	*f_init_player(void);
bool	f_is_position(char c);
char	**f_copy_tab(char **src);

//extract_data
char	**f_extract_data(char *file);
void	f_get_data(t_map *map, char **dat);

//pars_map
int		f_search_player(t_map *data, t_player *player);
void	f_size_maps(t_map *cub);
void	f_flood_fill(char **temp, t_map *cub, int x, int y);

#endif
