/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:28:05 by zmiantud          #+#    #+#             */
/*   Updated: 2018/06/05 09:31:31 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		int_len;
	char	*min_val;

	min_val = ft_strdup("-2147483648");
	if (n == -2147483648)
		return (min_val);
	int_len = ft_intlen(n);
	if (!(s = (char*)malloc(sizeof(char*) * (int_len + 1))))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	s[int_len] = '\0';
	while (n >= 10 && --int_len)
	{
		s[int_len] = n % 10 + '0';
		n = n / 10;
	}
	s[int_len - 1] = n + '0';
	return (s);
}
