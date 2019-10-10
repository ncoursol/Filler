/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 01:26:00 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/12 15:58:29 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display_include/display.h"

void		menu2(t_display v, int i)
{
	while (i >= 0)
	{
		mlx_pixel_put(v.mlx, v.win, (v.sc_w / 2) - 167, i, 0x00FFFF);
		mlx_pixel_put(v.mlx, v.win, (v.sc_w / 2) + 167, i, 0x00FFFF);
		i--;
	}
	mlx_string_put(v.mlx, v.win, v.sc_w / 2 - 64, 9, 0x00FFFF, "FILLER BATTLE");
	mlx_string_put(v.mlx, v.win, v.sc_w / 2 - 64, 30, 0x00FF00, " by ncoursol");
	mlx_string_put(v.mlx, v.win, v.sc_w / 8, 20, 0x8400FF, "PLAYER 1");
	mlx_string_put(v.mlx, v.win, v.sc_w / 5 * 4 - 5, 20, 0xFFFF00, "PLAYER 2");
	mlx_string_put(v.mlx, v.win, v.sc_w / 2 - 50 - ft_strlen(v.p1) * 10,
			100, 0x8400FF, v.p1);
	mlx_string_put(v.mlx, v.win, v.sc_w / 2 + 50, 100, 0xFFFF00, v.p2);
}

void		menu(t_display v)
{
	int		i;
	int		j;

	i = 0;
	while (i <= v.sc_w - 1)
	{
		mlx_pixel_put(v.mlx, v.win, i, 199, 0x00FFFF);
		i++;
	}
	i = 199;
	while (i >= 66)
	{
		mlx_pixel_put(v.mlx, v.win, v.sc_w / 2, i, 0x00FFFF);
		i--;
	}
	j = (v.sc_w / 2) - 167;
	while (j <= (v.sc_w / 2) + 167)
	{
		mlx_pixel_put(v.mlx, v.win, j, i, 0x00FFFF);
		j++;
	}
	menu2(v, i);
}
