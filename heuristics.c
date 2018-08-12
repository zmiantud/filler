/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 10:11:27 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/12 10:17:11 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int		south_west(t_data *data)
{
	int		i;
	int		j;

	i = data->m.y_map;
	while (i > 0)
	{
		j = 0;
		while (j < data->m.x_map)
		{
			if (piece_fit_test(i, j, data) == 1)
			{
				data->p_move.x = j;
				data->p_move.y = i;
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

static int		north_east(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->m.y_map)
	{
		j = data->m.x_map;
		while (j > 0)
		{
			if (piece_fit_test(i, j, data) == 1)
			{
				data->p_move.x = j;
				data->p_move.y = i;
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

static int		south_east(t_data *data)
{
	int i;
	int j;

	i = data->m.y_map;
	while (i > 0)
	{
		j = data->m.x_map;
		while (j > 0)
		{
			if (piece_fit_test(i, j, data) == 1)
			{
				data->p_move.x = j;
				data->p_move.y = i;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int		north_west(t_data *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < data->m.y_map)
	{
		j = 0;
		while (j < data->m.x_map)
		{
			if (piece_fit_test(i, j, data) == 1)
			{
				data->p_move.x = j;
				data->p_move.y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				heuristics(t_data *data)
{
	if (data->player_char == 'O')
	{
		if (data->tech == 1)
		{
			if (north_west(data) == 1)
			{
				return (data->p_move.piece_fit);
			}
		}
		else if (data->tech == 4)
			if (south_east(data) == 1)
				return (data->p_move.piece_fit);
	}
	else if (data->player_char == 'X')
	{
		if (data->tech == 3)
		{
			if (south_east(data) == 1)
				return (data->p_move.piece_fit);
		}
		else if (data->tech == 2)
			if (north_east(data) == 1)
				return (data->p_move.piece_fit);
	}
	return (0);
}
