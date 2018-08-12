/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_piece_coord.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:48:02 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/11 13:50:27 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	get_new_piece_coord(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->p.piece[y][x])
		x++;
	while (data->p.piece[y])
		y++;
	data->p.x_piece = 0;
	data->p.y_piece = 0;
	data->p.x_piece = x;
	data->p.y_piece = y;
}
