/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mundel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:55:58 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/09 20:34:42 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_rgb	init_rgb(int rgb)
{
	t_rgb	new;

	new.r = (rgb >> 16);
	new.g = (rgb >> 8) - (new.r << 8);
	new.b = rgb - ((rgb >> 8) << 8);
	return (new);
}

static int		con_rgb(t_rgb c)
{
	return ((c.r << 16) + (c.g << 8) + c.b);
}

static t_rgb	calc_rgb(t_rgb c1, t_rgb c2, char op)
{
	t_rgb	res;

	res = init_rgb(0);
	if (op == '+')
	{
		res.r = c1.r + c2.r;
		res.g = c1.g + c2.g;
		res.b = c1.b + c2.b;
	}
	if (op == '-')
	{
		res.r = c1.r - c2.r;
		res.g = c1.g - c2.g;
		res.b = c1.b - c2.b;
	}
	return (res);
}

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
	while (++i < e->max + 1)
		colors[i] = connect_rgb(i * 5, 1, i * 10);
	return (colors);
}

void	ft_mundel(t_e *e)
{
	int		i;
	int		j;
			double log_zn;
			double nu;
			double iter1;

	i = -1;
	e->colors = init_colors(e);
	while (++i < e->height)
	{
		j = -1;
		while (++j < e->width)
		{
			e->c_re = ((j - e->width / 2) * 4. +  (e->width * 1.) * e->x_sh * e->zo) / (e->width  * e->zo);
			e->c_im = ((i - e->height / 2) * 4. + (e->height * 1.) * e->y_sh * e->zo) / (e->height  * e->zo);
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
			if (e->iter < e->max)
			{
				log_zn = log(e->x * e->x + e->y * e->y) / 2;
				nu = log(log_zn / log(2)) / log(2);
				iter1 = e->iter + 1 - nu;
			}
			/*
			(e->iter < e->max) ? ft_img_px_put(e, j, i, e->colors[e->iter]) :
				ft_img_px_put(e, j, i, 0);
			*/
			t_rgb c1 = init_rgb(e->colors[(int)floor(iter1)]);
			t_rgb c2 = init_rgb(e->colors[(int)floor(iter1) + 1]);
			(e->iter < e->max) ? ft_img_px_put(e, j, i, con_rgb(calc_rgb(calc_rgb(c1, c2, '-'), c1, '+'))) : ft_img_px_put(e, j, i, 0);
		}

	}
}
