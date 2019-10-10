/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:25:00 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/23 12:14:48 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler_include/filler.h"

int			init_array(t_input *t, char **line)
{
	int		i;

	if (!t->array)
	{
		t->line = ft_atoi(*line + 7);
		i = 8;
		while ((*line)[i] != ' ')
			i++;
		t->col = ft_atoi(*line + i);
		i = 0;
		if (!(t->array = (char**)malloc(sizeof(char*) * (t->line + 1))))
			return (0);
		t->array[t->line] = NULL;
		while (i < t->line)
		{
			if (!(t->array[i] = (char*)malloc(sizeof(char) * (t->col + 1))))
				return (0);
			t->array[i][t->col] = '\0';
			i++;
		}
	}
	free(*line);
	return (1);
}

int			init_form(t_input *t)
{
	int		i;

	i = 0;
	if (!(t->form = (char**)malloc(sizeof(char*) * (t->f_line + 1))))
		return (0);
	t->form[t->f_line] = NULL;
	while (i < t->f_line)
	{
		if (!(t->form[i] = (char*)malloc(sizeof(char) * (t->f_col + 1))))
			return (0);
		t->form[i][t->f_col] = '\0';
		i++;
	}
	return (1);
}

void		free_alloc(t_input *t)
{
	int		i;

	i = 0;
	while (i < t->f_line)
	{
		free(t->form[i]);
		i++;
	}
	free(t->form);
	i = 0;
	while (i < t->line)
	{
		free(t->heat[i]);
		i++;
	}
	free(t->heat);
}

int			boucle(t_input *t, char **line)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while ((ret = get_next_line(0, line)))
	{
		if (!init_array(t, line))
			return (1);
		get_array(t, line);
		get_form_size(t, line);
		init_form(t);
		get_form(t, line);
		if (!heat_map(t))
			return (1);
		filler_algo(t);
		free_alloc(t);
	}
	return (0);
}

int			main(void)
{
	t_input		t;
	char		*line;
	int			i;

	init_var(&t);
	get_next_line(0, &line);
	t.nb = (line[10] == '1' ? 'O' : 'X');
	t.inv = (t.nb == 'O' ? 'X' : 'O');
	free(line);
	boucle(&t, &line);
	i = 0;
	while (i < t.line)
	{
		free(t.array[i]);
		i++;
	}
	free(t.array);
	return (0);
}
