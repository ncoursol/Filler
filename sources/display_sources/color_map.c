/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:50:00 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/12 16:39:55 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display_include/display.h"

void		square(t_display *v, int i, int j, int color)
{
	int		k;
	int		l;
	int		m;

	l = (v->im_h / v->line) * i + 2;
	while (l < i * (v->im_h / v->line) + (v->im_h / v->line) + 1)
	{
		m = (v->im_w / v->col) * j + 2;
		while (m < j * (v->im_w / v->col) + (v->im_w / v->col) + 1)
		{
			k = (((v->im_h - (v->im_h - l)) * v->im_w) - (v->im_w - m)) * 4;
			v->my_img[k + 0] = (color & 0xFF000000) >> 24;
			v->my_img[k + 1] = (color & 0x00FF0000) >> 16;
			v->my_img[k + 2] = (color & 0x0000FF00) >> 8;
			v->my_img[k + 3] = (color & 0x000000FF) >> 0;
			m++;
		}
		l++;
	}
}

void		color_map(t_display *v)
{
	int		i;
	int		j;

	i = 0;
	while (v->array[i])
	{
		j = 0;
		while (j < v->col)
		{
			if (v->array[i][j] == 'X')
				square(v, i, j, 0x00FFFF00 - i * (1000 - (8 * v->line)));
			else if (v->array[i][j] == 'x')
				square(v, i, j, 0x0000FF00 - i * (1000 - (8 * v->line)));
			else if (v->array[i][j] == 'O')
				square(v, i, j, 0xFF008300 - i * (1000 - (8 * v->line)));
			else if (v->array[i][j] == 'o')
				square(v, i, j, 0x0000FF00 - i * (1000 - (8 * v->line)));
			if (v->array[i][j] == 'X' || v->array[i][j] == 'x')
				v->s2++;
			else if (v->array[i][j] == 'O' || v->array[i][j] == 'o')
				v->s1++;
			j++;
		}
		i++;
	}
}

void		score_init(t_display *v)
{
	int		bpp;
	int		s_l;
	int		endian;
	int		i;

	v->hole = mlx_new_image(v->mlx, 60, 20);
	v->black = mlx_get_data_addr(v->hole, &(bpp), &(s_l), &(endian));
	i = 0;
	while (i < 60 * 20 * 4)
	{
		v->black[i] = 0x00;
		v->black[i + 1] = 0x00;
		v->black[i + 2] = 0x00;
		v->black[i + 3] = 0x00;
		i += 4;
	}
}

void		score(t_display *v)
{
	char	*k;

	mlx_put_image_to_window(v->mlx, v->win, v->hole, v->sc_w / 8, 100);
	mlx_put_image_to_window(v->mlx, v->win, v->hole, v->sc_w / 5 * 4 - 5, 100);
	k = ft_itoa(v->s1);
	mlx_string_put(v->mlx, v->win, v->sc_w / 8, 100, 0x8300FF, k);
	free(k);
	k = ft_itoa(v->s2);
	mlx_string_put(v->mlx, v->win, v->sc_w / 5 * 4 - 5, 100, 0xFFFF00, k);
	free(k);
	v->s1 = 0;
	v->s2 = 0;
}
