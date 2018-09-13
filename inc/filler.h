/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:25:31 by amalkevy          #+#    #+#             */
/*   Updated: 2018/05/11 13:25:35 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <locale.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <fcntl.h>

typedef struct	s_opt
{
	char		me;
	char		enemy;
	int			map_x;
	int			map_y;
	char		**map;
	int			p_x;
	int			p_y;
	char		**piece;
	int			me_coor[2];
	char		direct;
	char		way;
	char		flag;
}				t_opt;

void			mal_map(t_opt *inf, int fd);
void			read_map(t_opt *inf, int fd);
void			read_piece(t_opt *inf, int fd, char *line);
int				ft_checky(t_opt inf, int y, int x);
int				ft_dl(t_opt inf);
int				ft_dr(t_opt inf);
int				ft_ul(t_opt inf);
int				ft_ur(t_opt inf);
int				ft_ld(t_opt inf);
int				ft_lu(t_opt inf);
int				ft_rd(t_opt inf);
int				ft_ru(t_opt inf);
int				ft_left(t_opt *inf);
int				ft_right(t_opt *inf);
void			print_map(t_opt inf);
void			free_2d(char **chlen);

#endif
