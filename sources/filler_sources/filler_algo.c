/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:03:03 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/17 13:50:34 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler_include/filler.h"

void		place2(t_input *t, int p, int i, int j)
{
	p = (t->mode == 2 ? t->p1 - 1 : p);
	if (p < t->p1 && p > 0 && t->h1 == 1)
	{
		t->p1 = p;
		t->x1 = i;
		t->y1 = j;
	}
}

int			is_ok(t_input *t, int i, int j, int p)
{
	int		k;
	int		l;

	k = 0;
	while (k < t->f_line)
	{
		l = 0;
		while (l < t->f_col)
		{
			if (i + k >= t->line || j + l >= t->col || i + k < 0 || j + l < 0)
				return (0);
			if (t->form[k][l] == '*' && t->array[i + k][j + l] != '.'
					&& t->array[i + k][j + l] != t->nb)
				return (0);
			if (t->form[k][l] == '*' && t->array[i + k][j + l] == t->nb)
				t->h1++;
			if (t->form[k][l] == '*')
				p += t->heat[i + k][j + l];
			l++;
		}
		k++;
	}
	place2(t, p, i, j);
	return (1);
}

void		place(t_input *t)
{
	int		i;
	int		j;
	int		p;

	i = -t->f_line;
	while (i < t->line)
	{
		j = -t->f_col;
		while (j < t->col)
		{
			t->h1 = 0;
			p = 0;
			is_ok(t, i, j, p);
			j++;
		}
		i++;
	}
}

void		filler_algo(t_input *t)
{
	int		i;

	i = 0;
	t->mode = 0;
	while (i != 2 && t->x1 == -10 && t->y1 == -10)
	{
		place(t);
		t->mode = 2;
		i++;
	}
	ft_printf("%d %d\n", t->x1, t->y1);
	t->x1 = -10;
	t->y1 = -10;
	t->p1 = 10000;
}
