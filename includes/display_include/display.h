/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:18:10 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/17 14:58:34 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../../libraries/ft_printf/ft_printf.h"
# include "../../libraries/minilibx/mlx.h"
# include "../../libraries/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1380
# define BUF 1023

typedef	struct	s_display
{
	void		*mlx;
	void		*win;
	char		*my_img;
	void		*pt_img;
	char		*black;
	void		*hole;
	char		*p1;
	char		*p2;
	int			s1;
	int			s2;
	int			line;
	int			col;
	char		**array;
	int			sc_w;
	int			sc_h;
	int			im_w;
	int			im_h;
	int			diffw;
	int			diffh;
	int			end;
}				t_display;

int				read_vm_array_size(t_display *v);
int				read_vm_header(t_display *v, int mode);
void			menu(t_display v);
void			lines(t_display v);
int				init_array(t_display *v);
void			get_array(t_display *v);
void			square(t_display *v, int i, int j, int color);
void			color_map(t_display *v);
void			score_init(t_display *v);
void			score(t_display *v);
void			end_game(t_display *v);

#endif
