/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:26:57 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 13:27:00 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		ft_roz(int n)
{
	int		roz;

	roz = 1;
	while (n > 0 && roz++)
		n /= 10;
	roz--;
	return (roz);
}

void	mal_map(t_opt *inf, int fd)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(fd, &line);
	inf->map_y = ft_atoi((line) + 8);
	inf->map_x = ft_atoi((line) + 8 + ft_roz(inf->map_y));
	inf->map = (char**)malloc(sizeof(char*) * (inf->map_y + 1));
	while (i < inf->map_y)
		inf->map[i++] = (char*)malloc(sizeof(char) * (inf->map_x + 1));
	free(line);
}

void	read_map(t_opt *inf, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	*p;

	i = 0;
	while (i < inf->map_y)
	{
		get_next_line(fd, &line);
		p = line;
		line += 4;
		j = 0;
		while (j < inf->map_x)
		{
			inf->map[i][j++] = *line;
			line++;
		}
		inf->map[i++][inf->map_x] = '\0';
		ft_memdel((void**)&p);
	}
	inf->map[inf->map_y] = NULL;
}

void	read_piece(t_opt *inf, int fd, char *line)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	get_next_line(fd, &line);
	inf->p_y = ft_atoi(line + 6);
	inf->p_x = ft_atoi(line + 6 + ft_roz(inf->p_y));
	inf->piece = (char**)malloc(sizeof(char*) * (inf->p_y + 1));
	ft_memdel((void**)&line);
	while (i < inf->p_y)
	{
		get_next_line(fd, &line);
		p = line;
		j = 0;
		inf->piece[i] = (char*)malloc(sizeof(char) * (inf->p_x + 1));
		while (j < inf->p_x)
		{
			inf->piece[i][j++] = *line;
			line++;
		}
		ft_memdel((void**)&p);
		inf->piece[i++][inf->p_x] = '\0';
	}
	inf->piece[inf->p_y] = NULL;
}
