/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:29:05 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/17 14:58:40 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../../libraries/ft_printf/ft_printf.h"
# include "../../libraries/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define BUF 1023

typedef struct	s_input
{
	char		nb;
	char		inv;
	int			col;
	int			line;
	char		**array;
	int			f_col;
	int			f_line;
	char		**form;
	int			**heat;
	int			mode;
	int			x1;
	int			y1;
	int			h1;
	int			p1;
}				t_input;

int				heat_map(t_input *t);
void			filler_algo(t_input *t);
void			get_form(t_input *t, char **line);
void			get_form_size(t_input *t, char **line);
void			get_array(t_input *t, char **line);
void			init_var(t_input *t);

#endif
