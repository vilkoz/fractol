/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:03:44 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/10 19:32:24 by vrybalko         ###   ########.fr       */
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
	while (++i < e->max + 1)
		colors[i] = connect_rgb(i * 5, 1, i * 10);
	return (colors);
}

static void		ft_iterate(t_e *e)
{
	e->x_2 = e->x * e->x;
	e->y_2 = e->y * e->y;
	while (e->x * e->x + e->y * e->y < 4 && e->iter < e->max)
	{
		e->y = fabs(e->x * e->y);
		e->y += e->y + e->c_im;
		e->x = e->x_2 - e->y_2 + e->c_re;
		e->x_2 = e->x * e->x;
		e->y_2 = e->y * e->y;
		e->iter++;
	}
}

void			ft_burning(t_e *e)
{
	int		i;
	int		j;

	i = -1;
	e->colors = init_colors(e);
	while (++i < e->height)
	{
		j = -1;
		while (++j < e->width)
		{
			e->c_re = ((j - e->width / 2) * 4. + (e->width * 1.)
					* e->x_sh * e->zo) / (e->width * e->zo);
			e->c_im = ((i - e->height / 2) * 4. + (e->height * 1.)
					* e->y_sh * e->zo) / (e->height * e->zo);
			e->x = 0;
			e->y = 0;
			e->iter = 0;
			ft_iterate(e);
			(e->iter < e->max) ? ft_img_px_put(e, j, i, e->colors[e->iter]) :
				ft_img_px_put(e, j, i, 0);
		}
	}
	ft_img_px_put(e, e->width / 2, e->height / 2, 0xFFFFFF);
}
