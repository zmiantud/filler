/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 10:06:30 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/11 13:49:57 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	submit_coord(t_data *data)
{
	ft_putnbr(data->p_move.y - data->skipped_y);
	ft_putchar(' ');
	ft_putnbr(data->p_move.x - data->skipped_x);
	ft_putchar('\n');
}
