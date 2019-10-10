/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:52:11 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/12 15:58:18 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display_include/display.h"

void		init_var_disp2(t_display *v)
{
	v->mlx = mlx_init();
	v->sc_h = v->col > v->line ? 1200 : (v->line * 460) / v->col;
	v->sc_w = v->line > v->col ? 1000 : (v->col * 700) / v->line;
	v->sc_h = v->sc_h > 1380 ? 1380 : v->sc_h;
	v->sc_w = v->sc_w > 2100 ? 2100 : v->sc_w;
	v->sc_h = v->sc_h < 1200 ? 1200 : v->sc_h;
	v->sc_w = v->sc_w < 1000 ? 1000 : v->sc_w;
	v->win = mlx_new_window(v->mlx, v->sc_w, v->sc_h, "-- FILLER BATTLE --");
	v->im_h = v->sc_h - 240;
	v->im_w = v->sc_w - 40;
}

t_display	init_var_disp(t_display v)
{
	int		bpp;
	int		s_l;
	int		endian;

	v.s1 = 0;
	v.s2 = 0;
	v.end = 0;
	v.array = NULL;
	v.diffw = 0;
	v.diffh = 0;
	init_var_disp2(&v);
	while (v.im_h - 2 != (v.im_h / v.line) * v.line)
	{
		v.im_h--;
		v.diffh++;
	}
	while (v.im_w - 2 != (v.im_w / v.col) * v.col)
	{
		v.im_w--;
		v.diffw++;
	}
	v.pt_img = mlx_new_image(v.mlx, v.im_w, v.im_h);
	v.my_img = mlx_get_data_addr(v.pt_img, &(bpp), &(s_l), &(endian));
	return (v);
}

int			key_press(int key, t_display *v)
{
	if (key == 53)
	{
		end_game(v);
		exit(0);
	}
	return (0);
}

int			boucle(t_display *v)
{
	if (v->end == 0)
		get_array(v);
	if (v->end == 0)
		color_map(v);
	if (v->end == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->pt_img \
				, 19 + v->diffw / 2, 219 + v->diffh / 2);
	if (v->end == 0)
		score(v);
	return (0);
}

int			main(void)
{
	t_display	v;

	if (!read_vm_header(&v, 1) || !read_vm_header(&v, 2)
			|| !read_vm_array_size(&v))
		return (0);
	v = init_var_disp(v);
	menu(v);
	mlx_put_image_to_window(v.mlx, v.win, v.pt_img,
			19 + v.diffw / 2, 219 + v.diffh / 2);
	if (!init_array(&v))
		return (0);
	score_init(&v);
	mlx_loop_hook(v.mlx, boucle, &v);
	mlx_hook(v.win, 2, 0, key_press, &v);
	mlx_loop(v.mlx);
	return (0);
}
