/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:42:09 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/13 11:13:23 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display_include/display.h"

int			player1(t_display *v, int i, int j, char *line)
{
	j = j - i;
	if (!(v->p1 = (char*)malloc(sizeof(char) * (j + 1))))
		return (1);
	v->p1[j] = '\0';
	j = 0;
	while (line[i] != '.')
	{
		v->p1[j] = line[i];
		j++;
		i++;
	}
	return (0);
}

int			player2(t_display *v, int i, int j, char *line)
{
	j = j - i;
	if (!(v->p2 = (char*)malloc(sizeof(char) * (j + 1))))
		return (1);
	v->p2[j] = '\0';
	j = 0;
	while (line[i] != '.')
	{
		v->p2[j] = line[i];
		j++;
		i++;
	}
	return (0);
}

void		read_player(char *line, int *i, int *j)
{
	*i = 0;
	while (line[*i] != ']')
		*i += 1;
	*j = *i - 7;
	while (line[*i] != '/' && line[*i] != '[')
		*i -= 1;
	*i += 1;
}

int			read_vm_header(t_display *v, int mode)
{
	char	*line;
	int		i;
	int		j;

	get_next_line(0, &line);
	while (line[0] != '$')
	{
		free(line);
		get_next_line(0, &line);
	}
	read_player(line, &i, &j);
	if (mode == 1)
	{
		if (player1(v, i, j, line))
			return (0);
	}
	if (mode == 2)
	{
		if (player2(v, i, j, line))
			return (0);
	}
	free(line);
	return (1);
}

int			read_vm_array_size(t_display *v)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	v->line = ft_atoi(line + 7);
	i = 8;
	while (line[i] != ' ')
		i++;
	v->col = ft_atoi(line + i);
	free(line);
	return (1);
}
