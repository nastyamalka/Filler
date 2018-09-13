/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:27:59 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 13:29:44 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		ft_right(t_opt *inf)
{
	int i;

	i = 0;
	if (inf->way == 1)
	{
		if (inf->flag == 1)
		{
			inf->flag = 2;
			i = ft_ur(*inf);
		}
		else if (inf->flag == 2)
		{
			inf->flag = 1;
			i = ft_ld(*inf);
		}
	}
	return (i);
}
