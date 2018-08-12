/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:39:15 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/12 12:16:19 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 && s2)
	{
		res = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
		if (res)
		{
			res = ft_strcat(res, (char*)s1);
			res = ft_strcat(res, (char*)s2);
			return (res);
		}
	}
	return (NULL);
}
