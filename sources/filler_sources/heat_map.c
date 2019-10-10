/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:23:53 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/17 13:25:18 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler_include/filler.h"

int		init_heat_map(t_input *t)
{
	int		i;
	int		j;

	i = 0;
	if (!(t->heat = (int**)malloc(sizeof(int*) * t->line)))
		return (0);
	while (i < t->line)
	{
		if (!(t->heat[i] = (int*)malloc(sizeof(int) * t->col)))
			return (0);
		i++;
	}
	i = 0;
	while (i < t->line)
	{
		j = 0;
		while (j < t->col)
		{
			t->heat[i][j] = -2;
			j++;
		}
		i++;
	}
	return (1);
}

void	heat3(t_input *t, int k, int l, int a)
{
	if (k + 1 < t->line && l + 1 < t->col && t->heat[k + 1][l + 1] == -2)
		t->heat[k + 1][l + 1] = a + 1;
	if (k + 1 < t->line && t->heat[k + 1][l] == -2)
		t->heat[k + 1][l] = a + 1;
	if (k + 1 < t->line && l - 1 >= 0 && t->heat[k + 1][l - 1] == -2)
		t->heat[k + 1][l - 1] = a + 1;
	if (l + 1 < t->col && t->heat[k][l + 1] == -2)
		t->heat[k][l + 1] = a + 1;
	if (l - 1 >= 0 && t->heat[k][l - 1] == -2)
		t->heat[k][l - 1] = a + 1;
	if (k - 1 >= 0 && l + 1 < t->col && t->heat[k - 1][l + 1] == -2)
		t->heat[k - 1][l + 1] = a + 1;
	if (k - 1 >= 0 && t->heat[k - 1][l] == -2)
		t->heat[k - 1][l] = a + 1;
	if (k - 1 >= 0 && l - 1 >= 0 && t->heat[k - 1][l - 1] == -2)
		t->heat[k - 1][l - 1] = a + 1;
}

void	heat2(t_input *t, int a)
{
	int		k;
	int		l;

	while (a <= (t->line > t->col ? t->line : t->col))
	{
		k = 0;
		while (k < t->line)
		{
			l = 0;
			while (l < t->col)
			{
				if (t->heat[k][l] == a)
					heat3(t, k, l, a);
				l++;
			}
			k++;
		}
		a++;
	}
}

int		heat_map(t_input *t)
{
	int		i;
	int		j;
	int		a;

	if (!init_heat_map(t))
		return (0);
	a = 1;
	i = 0;
	while (i < t->line)
	{
		j = 0;
		while (j < t->col)
		{
			if (t->array[i][j] == 'O' || t->array[i][j] == 'o')
				t->heat[i][j] = (t->nb == 'O' ? -1 : 1);
			else if (t->array[i][j] == 'X' || t->array[i][j] == 'x')
				t->heat[i][j] = (t->nb == 'X' ? -1 : 1);
			j++;
		}
		i++;
	}
	heat2(t, a);
	return (1);
}
