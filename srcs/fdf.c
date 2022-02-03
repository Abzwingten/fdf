#include "ft_fdf.h"

int main(int argc, char **argv)
{
	t_environment emu;
	char *file;
	char **map;
	int fd;

	map = (char **)malloc(sizeof(char *) * 1000);
	ft_bzero(map, 1000);
	fd = open(argv[argc - 1], O_RDONLY);
	emu.row = 0;
	ft_error(argc, fd);
	while (get_next_line(fd, &file) > 0)
	{
		map[emu.row] = ft_strdup(file);
		emu.row++;
	}
	map[emu.row] = 0;
	emu.matrix = make_matrix(map, &emu);
	create_window(&emu);
	close(fd);
	return (0);
}

void ft_error(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putendl("Invalid number of arguments");
		exit(0);
	}
	if (fd == -1)
	{
		ft_putendl("File missing");
		exit(0);
	}
}

void create_window(t_environment *emu)
{
	int i;

	i = 0;
	set_basic(emu);
	emu->pts = (t_point **)malloc(sizeof(t_point) * emu->row);
	emu->trans = (t_point **)malloc(sizeof(t_point) * emu->row);
	emu->init = (t_point **)malloc(sizeof(t_point) * emu->row);
	while (i < emu->row)
	{
		emu->pts[i] = (t_point *)malloc(sizeof(t_point) * emu->col);
		emu->trans[i] = (t_point *)malloc(sizeof(t_point) * emu->col);
		emu->init[i++] = (t_point *)malloc(sizeof(t_point) * emu->col);
	}
	make_points(emu);
	translate(emu);
	emu->mlx = mlx_init();
	emu->window = mlx_new_window(emu->mlx, WIDTH, HEIGHT, "fdf");
	emu->image = mlx_new_image(emu->mlx, WIDTH, HEIGHT);
	mlx_hook(emu->window, 2, 3, key_handling, emu);
	mlx_loop_hook(emu->mlx, &main_activity, emu);
	mlx_loop(emu->mlx);
}

void set_basic(t_environment *emu)
{
	emu->scale = 30;
	emu->scale_z = 2;
	emu->x_offset = WIDTH / 2;
	emu->y_offset = HEIGHT / 2;
	emu->projection = 0;
	emu->color = 0;
}

int main_activity(t_environment *emu)
{
	img_clear(emu);
	draw_picture_1(emu);
	draw_picture_2(emu);
	mlx_put_image_to_window(emu->mlx, emu->window, emu->image, 0, 0);
	ft_draw_controls(emu);
	return (0);
}

void ft_draw_controls(t_environment *emu)
{
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 70, 0x00FFFF00, "W/A/S/D to move image");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 60, 0x00FFFF00, "-/+ to scale image");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 50, 0x00FFFF00, "R/G/B - to change colors");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 40, 0x00FFFF00, "Q/E - for x axis rotation");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 30, 0x00FFFF00, "arrow up/arrow down - for z axis rotation");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 20, 0x00FFFF00, "arrow left/arrow right - for y axis rotation");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 10, 0x00FFFF00, "ESC - for exit");
}
