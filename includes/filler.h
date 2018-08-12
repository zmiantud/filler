/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmiantud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 09:56:40 by zmiantud          #+#    #+#             */
/*   Updated: 2018/08/12 10:49:57 by zmiantud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct			s_move
{
	int					x;
	int					y;
	int					piece_fit;
}						t_move;

typedef struct			s_map
{
	char				**map;
	int					x_map;
	int					y_map;
}						t_map;

typedef struct			s_piece
{
	char				**piece;
	char				**trimmed_piece;
	int					x_piece;
	int					y_piece;
}						t_piece;

typedef struct			s_data
{
	char				player_char;
	char				adv_char;
	int					tech;
	int					cannot_move;
	int					skipped_x;
	int					skipped_y;
	t_map				m;
	t_piece				p;
	t_move				p_move;
}						t_data;

void					get_tables(t_data *data);
int						heuristics(t_data *data);
void					submit_coord(t_data *data);
int						piece_fit_test(int x, int y, t_data *data);
void					arraydel(char **arr);
char					**trim_piece(char **token, t_data *data);
void					set_next_strategy(t_data *data);
void					get_new_piece_coord(t_data *data);

#endif
