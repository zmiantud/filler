/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_fit_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:21:57 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/11 13:50:38 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		overboard_test(int i, int j, t_data *data)
{
	if (i + data->p.y_piece > data->m.y_map)
		return (1);
	if (j + data->p.x_piece > data->m.x_map)
		return (1);
	return (0);
}

int		piece_fit_test(int i, int j, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	data->p_move.piece_fit = 0;
	if (overboard_test(i, j, data))
		return (0);
	while (y < data->p.y_piece)
	{
		x = 0;
		while (x < data->p.x_piece)
		{
			if ((data->m.map[i + y][x + j] == data->player_char ||
				data->m.map[i + y][x + j] == ft_tolower(data->player_char))
				&& data->p.piece[y][x] == '*')
				data->p_move.piece_fit++;
			if ((data->m.map[i + y][x + j] == data->adv_char ||
				data->m.map[i + y][x + j] == ft_tolower(data->adv_char))
				&& data->p.piece[y][x] == '*')
				return (0);
			x++;
		}
		y++;
	}
	return (data->p_move.piece_fit);
}
