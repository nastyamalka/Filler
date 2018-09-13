/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:26:16 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 13:26:25 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int		ft_zero(t_opt *inf)
{
	int		i;

	i = 0;
	if (inf->flag == 1)
	{
		inf->flag = 2;
		i = ft_ru(*inf);
		if (i == 2 && (inf->direct == 12 || inf->direct == 32))
			inf->way = 2;
	}
	else if (inf->flag == 2)
	{
		inf->flag = 1;
		i = ft_ld(*inf);
		if (i == 2 && (inf->direct == 12 || inf->direct == 32))
			inf->way = 3;
	}
	return (i);
}

static int		ft_second(t_opt *inf)
{
	int		i;

	i = 0;
	if (inf->flag == 1)
	{
		inf->flag = 2;
		i = ft_dr(*inf);
		if (i == 2)
			inf->way = 4;
	}
	else if (inf->flag == 2)
	{
		inf->flag = 1;
		i = ft_ld(*inf);
		if (i == 2)
			inf->way = 5;
	}
	return (i);
}

static int		ft_third(t_opt *inf)
{
	int		i;

	i = 0;
	if (inf->flag == 1)
	{
		inf->flag = 2;
		i = ft_dr(*inf);
		if (i == 2)
			inf->way = 6;
	}
	else if (inf->flag == 2)
	{
		inf->flag = 1;
		i = ft_ru(*inf);
		if (i == 2)
			inf->way = 7;
	}
	return (i);
}

static int		ft_four(t_opt *inf)
{
	if (inf->way == 4)
	{
		if (inf->flag == 1 && (inf->flag = 2))
			return (ft_ru(*inf));
		else if (inf->flag == 2 && (inf->flag = 1))
			return (ft_dl(*inf));
	}
	else if (inf->way == 5)
	{
		if (inf->flag == 1 && (inf->flag = 2))
			return (ft_dr(*inf));
		else if (inf->flag == 2 && (inf->flag = 1))
			return (ft_ru(*inf));
	}
	return (0);
}

int				ft_left(t_opt *inf)
{
	if (inf->way == 0)
		return (ft_zero(inf));
	else if (inf->way == 2)
		return (ft_second(inf));
	else if (inf->way == 3)
		return (ft_third(inf));
	if (inf->way == 4 || inf->way == 5)
		return (ft_four(inf));
	else if (inf->way == 6)
	{
		if (inf->flag == 1 && (inf->flag = 2))
			return (ft_ru(*inf));
		else if (inf->flag == 2 && (inf->flag = 1))
			return (ft_ur(*inf));
	}
	else if (inf->way == 7)
	{
		if (inf->flag == 1 && (inf->flag = 2))
			return (ft_ld(*inf));
		else if (inf->flag == 2 && (inf->flag = 1))
			return (ft_ru(*inf));
	}
	return (0);
}
