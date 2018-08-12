/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tables.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:53:58 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/12 10:53:18 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static void		ft_get_map(t_data *data)
{
	char	*line;
	int		i;
	char	**mp;

	i = 0;
	get_next_line(0, &line);
	if (!(mp = (char **)malloc(sizeof(char *) * data->m.y_map + 1)))
		return ;
	while (i < data->m.y_map)
	{
		get_next_line(0, &line);
		mp[i] = ft_strdup(line + 4);
		i++;
	}
	mp[i] = NULL;
	data->m.map = mp;
}

static void		ft_get_piece(t_data *data)
{
	char	*line;
	char	i;
	int		n;
	char	**pc;

	i = 0;
	n = 6;
	get_next_line(0, &line);
	data->p.y_piece = ft_atoi(&line[6]);
	while (ft_isdigit(line[n]))
		n++;
	n++;
	data->p.x_piece = ft_atoi(&line[n]);
	if (!(pc = (char **)malloc(sizeof(char *) * data->p.y_piece + 1)))
		return ;
	while (i < data->p.y_piece)
	{
		get_next_line(0, &line);
		pc[i] = ft_strdup(line);
		i++;
	}
	pc[i] = NULL;
	data->p.piece = pc;
}

void			get_tables(t_data *data)
{
	char	**trim_p;

	ft_get_map(data);
	ft_get_piece(data);
	if (!(trim_p = (char **)malloc(sizeof(char))))
		return ;
	trim_p = trim_piece(data->p.piece, data);
	data->p.trimmed_piece = trim_p;
	data->p.piece = trim_p;
	get_new_piece_coord(data);
}
