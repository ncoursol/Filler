/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:32:03 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/17 13:40:58 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler_include/filler.h"

void		get_form(t_input *t, char **line)
{
	int		i;

	i = 0;
	while (i < t->f_line)
	{
		get_next_line(0, line);
		t->form[i] = ft_strcpy(t->form[i], *line);
		free(*line);
		i++;
	}
}

void		get_form_size(t_input *t, char **line)
{
	int		i;

	i = 6;
	get_next_line(0, line);
	t->f_line = ft_atoi(*line + 5);
	while ((*line)[i] != ' ')
		i++;
	t->f_col = ft_atoi(*line + i);
	free(*line);
}

void		get_array(t_input *t, char **line)
{
	int		i;

	get_next_line(0, line);
	free(*line);
	i = 0;
	while (i < t->line)
	{
		get_next_line(0, line);
		t->array[i] = ft_strcpy(t->array[i], *line + 4);
		free(*line);
		i++;
	}
}

void		init_var(t_input *t)
{
	t->nb = '~';
	t->inv = '~';
	t->col = -10;
	t->line = -10;
	t->f_col = -10;
	t->f_line = -10;
	t->array = NULL;
	t->form = NULL;
	t->p1 = 10000;
	t->mode = 0;
	t->x1 = -10;
	t->y1 = -10;
	t->h1 = 0;
}
