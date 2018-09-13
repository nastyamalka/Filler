/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findplace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:40:17 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 14:40:19 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		ft_checky(t_opt inf, int y, int x)
{
	int		cross;
	int		i;
	int		j;

	if ((y + inf.p_y > inf.map_y) || (x + inf.p_x > inf.map_x))
		return (-1);
	cross = 0;
	i = -1;
	while (++i < inf.p_y)
	{
		j = 0;
		while (j < inf.p_x)
		{
			if ((inf.map[i + y][j + x] == inf.enemy || inf.map[i + y][j + x]
				== inf.enemy + 32) && inf.piece[i][j] != '.')
				return (-3);
			if (((inf.map[i + y][j + x] == inf.me && inf.piece[i][j]
		!= '.') || (inf.map[i + y][j + x] == inf.me + 32 && inf.piece[i][j]
		!= '.')) && ++cross)
				if (cross > 1)
					return (-2);
			j++;
		}
	}
	return (cross);
}

int		ft_dl(t_opt inf)
{
	int		i;
	int		j;

	i = inf.map_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < inf.map_x)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (i == inf.map_y - 1 &&
					ft_strchr(inf.piece[inf.p_y - 1], '*') != 0)
					return (2);
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int		ft_dr(t_opt inf)
{
	int		i;
	int		j;

	i = inf.map_y - 1;
	while (i >= 0)
	{
		j = inf.map_x - 1;
		while (j >= 0)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (i == inf.map_y - 1 &&
					ft_strchr(inf.piece[inf.p_y - 1], '*') != 0)
					return (2);
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int		ft_ul(t_opt inf)
{
	int		i;
	int		j;

	i = 0;
	while (i < inf.map_y)
	{
		j = 0;
		while (j < inf.map_x)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (i == 0 && ft_strchr(inf.piece[0], '*') != 0)
					return (2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_ur(t_opt inf)
{
	int		i;
	int		j;

	i = 0;
	while (i < inf.map_y)
	{
		j = inf.map_x - 1;
		while (j >= 0)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (i == 0 && ft_strchr(inf.piece[0], '*') != 0)
					return (2);
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}
