/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:45:22 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/04 12:19:49 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display_include/display.h"

void		end_game(t_display *v)
{
	free(v->p1);
	free(v->p2);
	free(v->array);
	mlx_destroy_window(v->mlx, v->win);
}

int			init_array(t_display *v)
{
	int		i;

	i = 0;
	if (!(v->array = (char**)malloc(sizeof(char*) * (v->line + 1))))
		return (0);
	v->array[v->line] = NULL;
	while (i < v->line)
	{
		if (!(v->array[i] = (char*)malloc(sizeof(char) * (v->col + 1))))
			return (0);
		v->array[i][v->col] = '\0';
		i++;
	}
	return (1);
}

void		get_array2(t_display *v, char *line)
{
	int		i;
	int		j;

	i = 0;
	if (v->end == 0)
	{
		while (i < v->line)
		{
			j = 0;
			while (j < v->col)
			{
				v->array[i][j] = line[j + 4];
				j++;
			}
			free(line);
			get_next_line(0, &line);
			i++;
		}
		free(line);
	}
}

void		get_array(t_display *v)
{
	char	*line;

	get_next_line(0, &line);
	while (!ft_isdigit(line[0]))
	{
		if (line[0] == '=')
		{
			free(line);
			v->end = 1;
			break ;
		}
		free(line);
		get_next_line(0, &line);
	}
	get_array2(v, line);
}
