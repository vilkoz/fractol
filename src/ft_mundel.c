/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mundel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:55:58 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/08 21:09:31 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		connect_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int		*init_colors(t_e *e)
{
	int		i;
	int		*colors;

	i = -1;
	colors = (int *)malloc(sizeof(int) * e->max);
	while (++i < e->max)
		colors[i] = connect_rgb(i * 10, 1, i / (i + 8));
	return (colors);
}

void	ft_mundel(t_e *e)
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
			e->c_re = ((j - e->width / 2 + e->x_sh) * 4. / e->width) / 1. * e->zo;
			e->c_im = ((i - e->height / 2 + e->y_sh) * 4. / e->height) / 1. * e->zo;
			e->x = 0;
			e->y = 0;
			e->iter = 0;
			while (e->x * e->x + e->y * e->y < 4 && e->iter < e->max)
			{
				e->x_2 = e->x * e->x - e->y * e->y + e->c_re;
				e->y_2 = 2 * e->x * e->y + e->c_im;
				if (e->x == e->x_2 && e->y == e->y_2)
				{
					e->iter = e->max;
					break;
				}
				e->x = e->x_2;
				e->y = e->y_2;
				e->iter++;
			}
			(e->iter < e->max) ? ft_img_px_put(e, j, i, e->colors[e->iter]) :
				ft_img_px_put(e, j, i, 0);
		}

	}
}
