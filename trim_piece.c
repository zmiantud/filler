/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:53:38 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/12 10:54:15 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static char		**trim_horiz(char **token, int *skipped_y)
{
	size_t	y;
	size_t	end;
	size_t	start;
	char	**ret;

	y = 0;
	while (token[y] && !ft_strchr(token[y], '*'))
		y++;
	start = y;
	*skipped_y = y;
	while (token[y] && ft_strchr(token[y], '*'))
	{
		y++;
	}
	end = y;
	if (!(ret = (char **)malloc(sizeof(char*) * (end - start + 1))))
		return (0);
	y = -1;
	while (start < end)
		ret[++y] = ft_strdup(token[start++]);
	ret[++y] = NULL;
	arraydel(token);
	return (ret);
}

static int		trim_vertic_left(char **token, int *skipped_x)
{
	int	y;
	int	x;
	int	numb_col;
	int	numb_row;

	x = 0;
	numb_col = 0;
	numb_row = 0;
	while (token[0][numb_col])
		numb_col++;
	while (token[numb_row])
		numb_row++;
	while (x < numb_col)
	{
		y = 0;
		while (y < numb_row)
		{
			*skipped_x = (token[y][x] == '*') ? x : *skipped_x;
			if (token[y][x] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

static int		trim_vertic_right(char **token)
{
	int y;
	int numb_col;
	int numb_row;

	numb_col = 0;
	numb_row = 0;
	while (token[0][numb_col])
		numb_col++;
	while (token[numb_row])
		numb_row++;
	while (--numb_col >= 0)
	{
		y = 0;
		while (y < numb_row)
		{
			if (token[y][numb_col] == '*')
				return (numb_col);
			y++;
		}
	}
	return (0);
}

char			**trim_piece(char **token, t_data *data)
{
	size_t		st_start;
	size_t		st_end;
	int			n;
	char		**ret;
	char		**trimmed_h;

	trimmed_h = trim_horiz(token, &n);
	data->skipped_y = n;
	token = trimmed_h;
	st_start = trim_vertic_left(token, &n);
	data->skipped_x = n;
	st_end = trim_vertic_right(token) + 1;
	n = 0;
	while (token[n] != NULL)
		n++;
	ret = (char **)malloc(sizeof(char*) * (n + 1));
	n = -1;
	while (token[++n] != NULL)
		ret[n] = ft_strsub(token[n], st_start, (st_end - st_start));
	ret[n] = NULL;
	arraydel(token);
	return (ret);
}
