/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findplace2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:42:15 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 14:42:17 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		ft_strchrcolm(char **s, char c, char fl)
{
	int		i;
	int		j;

	i = 0;
	if (fl == 'l')
	{
		j = ft_strlen(s[0]) - 1;
		while (s[i] != NULL)
		{
			if (s[i][j] == c)
				return (1);
			i++;
		}
	}
	if (fl == 'f')
	{
		while (s[i] != NULL)
		{
			if (s[i][0] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

int		ft_ld(t_opt inf)
{
	int		i;
	int		j;

	j = 0;
	while (j < inf.map_x)
	{
		i = inf.map_y - 1;
		while (i >= 0)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (j == 0 && ft_strchrcolm(inf.piece, '*', 'f') != 0)
					return (2);
				return (1);
			}
			i--;
		}
		j++;
	}
	return (0);
}

int		ft_lu(t_opt inf)
{
	int		i;
	int		j;

	j = 0;
	while (j < inf.map_x)
	{
		i = 0;
		while (i < inf.map_y)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (j == 0 && ft_strchrcolm(inf.piece, '*', 'f') != 0)
					return (2);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_rd(t_opt inf)
{
	int		i;
	int		j;

	j = inf.map_x - 1;
	while (--j >= 0)
	{
		i = inf.map_y - 1;
		while (i >= 0)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (j + inf.p_x + 1 == inf.map_x
					&& ft_strchrcolm(inf.piece, '*', 'l') != 0)
					return (2);
				return (1);
			}
			i--;
		}
	}
	return (0);
}

int		ft_ru(t_opt inf)
{
	int		i;
	int		j;

	j = inf.map_x - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < inf.map_y)
		{
			if (ft_checky(inf, i, j) == 1)
			{
				ft_printf("%i %i\n", i, j);
				if (j + inf.p_x == inf.map_x - 2 &&
					ft_strchrcolm(inf.piece, '*', 'l') != 0)
					return (2);
				return (1);
			}
			i++;
		}
		j--;
	}
	return (0);
}
