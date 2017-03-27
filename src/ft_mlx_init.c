/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:25:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/27 14:40:50 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int		connect_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

static int		*init_colors(t_e *e)
{
	int		i;
	int		*colors;

	i = -1;
	colors = (int *)malloc(sizeof(int) * e->max);
	while (++i < e->max)
		colors[i] = connect_rgb(i * 5, 1, i * 10);
	return (colors);
}

t_e		*ft_mlx_init(char *s, int type, t_e *e)
{
	if (e->mlx == NULL)
		e->mlx = mlx_init();
	e->height = 700;
	e->width = 700;
	e->x_sh = 0;
	e->y_sh = 0;
	e->zo = 1;
	e->win = mlx_new_window(e->mlx, e->width, e->height, s);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->max = 30;
	e->f_type = type;
	e->c_re = -0.7;
	e->c_im = 0.27015;
	e->r_sh = 0;
	e->lst = NULL;
	e->colors = init_colors(e);
	return (e);
}
