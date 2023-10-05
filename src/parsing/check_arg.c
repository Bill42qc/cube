#include "../cube.h"

void	f_error(char *msg, t_map *data)
{
	ft_putstr_fd(msg, 2);
	f_free_tmap(data);
	exit(EXIT_FAILURE);
}

int	f_check_cub(char *str)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".cub", 5) == 0)
		return (1);
	return (0);
}

void	f_check_arg(int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc != 2)
		f_error(E_ARGS_NUM, NULL);
	else
	{
		fd = open(argv[1], O_RDONLY);
		str = get_next_line(fd);
		if (fd < 0 || str == NULL || f_check_cub(argv[1]) == 0)
		{
			close(fd);
			str = f_freenull(str);
			f_error(E_FILE_NAME, NULL);
		}
		str = f_freenull(str);
	}
}

void	f_pars_file(int ac, char **av, t_data *data)
{
	char	**dat;

	f_check_arg(ac, av);
	dat = f_extract_data(av[1]);
	f_get_data(data->map, dat);
	ft_free_tab_char(dat);
	if (f_search_player(data->map, data->player) != 1)
		f_error(E_FLOODFILL, data->map);
	f_size_maps(data->map);
	dat = f_copy_tab(data->map->map);
	f_flood_fill(dat, data->map, data->player->x, data->player->y);
	ft_free_tab_char(dat);
}
