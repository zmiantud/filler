/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:19:05 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/12 10:15:24 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static void		init_don(t_data *data)
{
	data->m.y_map = 0;
	data->m.x_map = 0;
	data->p.x_piece = 0;
	data->p.y_piece = 0;
	data->p_move.x = 0;
	data->p_move.y = 0;
	data->p_move.piece_fit = 0;
	data->skipped_y = 0;
	data->skipped_x = 0;
}

static void		get_map_x_y(char *s, t_data *data)
{
	if (s)
	{
		data->m.y_map = ft_atoi(&s[8]);
		data->m.x_map = ft_atoi(&s[11]);
	}
}

int				main(void)
{
	char	*line;
	t_data	data;

	get_next_line(0, &line);
	data.player_char = (ft_atoi(&line[10]) == 1) ? 'O' : 'X';
	data.adv_char = (data.player_char == 'O') ? 'X' : 'O';
	data.tech = (data.player_char == 'O') ? 1 : 3;
	while (1)
	{
		if (get_next_line(0, &line) < 1)
			break ;
		init_don(&data);
		get_map_x_y(line, &data);
		get_tables(&data);
		if (heuristics(&data) == 0)
		{
			write(1, "1 9\n", 4);
			break ;
		}
		submit_coord(&data);
		set_next_strategy(&data);
		arraydel(data.m.map);
		arraydel(data.p.piece);
	}
	return (0);
}
