/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraydel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:30:09 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/11 13:50:09 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	arraydel(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	i--;
	while (i >= 0)
	{
		ft_strdel(&arr[i]);
		i--;
	}
	free(arr);
	arr = NULL;
}
