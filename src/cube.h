/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:36 by bmartin           #+#    #+#             */
/*   Updated: 2023/09/25 14:41:54 by rofontai         ###   ########.fr       */
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
# define E_ARGS_NUM "Error\nArgument Number is wrong\n"

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
	char		**map;
	int			map_height;
	int			map_width;

}					t_map;

typedef struct s_player
{
	int				x;
	int				y;
	float			angle;

}				t_player;

typedef struct s_dm
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char*		floor;
	char*		ceiling;
	char	**map;
}			t_dm;


//function

// PARSING

//check_arg
void	f_error(char *msg);
int		f_check_cub(char *str);
void	f_check_arg(int argc, char **argv);

//check_file
void	f_print_dm(t_dm *data_map);
void	f_print_tab(char **cou);
void	*f_freenull(void *str);
void	f_print_file(char *file);
char 	**f_extract_data(char *file);
bool 	f_its_here(char *src, char *search);
t_dm 	*f_get_good_map(char **dat);

//pars_data
char *f_pars_direction(char *line, char *dir);
char	*f_pars_colors(char *line, char *dir);

#endif
