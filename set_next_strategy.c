/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_next_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:22:00 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/11 10:23:24 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	set_next_strategy(t_data *data)
{
	if (data->player_char == 'O')
	{
		if (data->tech == 1)
			data->tech = 4;
		else if (data->tech == 4)
			data->tech = 1;
	}
	else
	{
		if (data->tech == 3)
			data->tech = 2;
		else if (data->tech == 2)
			data->tech = 3;
	}
}
