/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:51:44 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 15:23:41 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	free_2d(char **chlen)
{
	int		i;

	i = 0;
	while (chlen[i])
	{
		ft_memdel((void**)&chlen[i]);
		i++;
	}
	ft_memdel((void**)&chlen);
}

int		ft_do(t_opt *inf)
{
	int i;

	i = 0;
	if (inf->way == 0 || inf->way == 2 || inf->way == 3 ||
			inf->way == 4 || inf->way == 5 || inf->way == 6 || inf->way == 7)
		i = ft_left(inf);
	if (inf->way == 1 || inf->way == 8 || inf->way == 9 || inf->way == 10
			|| inf->way == 11 || inf->way == 12 || inf->way == 13)
		i = ft_right(inf);
	return (i);
}

void	ft_find_coor(t_opt *inf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < inf->map_y)
	{
		j = -1;
		while (++j < inf->map_x)
		{
			if (inf->map[i][j] == inf->me)
			{
				if (inf->map_x / 2 > j)
					inf->way = 0;
				else
					inf->way = 1;
			}
		}
	}
}

void	who_am_i(t_opt *inf, char *line)
{
	if (ft_strstr(line, "exec p2") != 0)
	{
		inf->me = 'X';
		inf->enemy = 'O';
	}
	else
	{
		inf->me = 'O';
		inf->enemy = 'X';
	}
	inf->me_coor[0] = -1;
	inf->way = -1;
	inf->flag = 1;
}

int		main(void)
{
	char		*line;
	t_opt		inf;

	line = NULL;
	if (get_next_line(0, &line) == -1)
		return (0);
	who_am_i(&inf, line);
	free(line);
	mal_map(&inf, 0);
	while (get_next_line(0, &line) > 0)
	{
		free(line);
		if (ft_strstr(line, "Plateau") != NULL
				&& get_next_line(0, &line) != -1)
			free(line);
		read_map(&inf, 0);
		read_piece(&inf, 0, line);
		if (inf.way == -1)
			ft_find_coor(&inf);
		ft_do(&inf);
		free_2d(inf.piece);
	}
	free_2d(inf.map);
	return (0);
}
