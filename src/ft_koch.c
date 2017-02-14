/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_koch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:05:55 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/14 18:21:46 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_lin		line_init(t_p p1, t_p p2)
{
	t_lin	lin;

	lin.dx = fabs(p2.x - p1.x);
	lin.dy = fabs(p2.y - p1.y);
	lin.sx = p1.x < p2.x ? 1 : -1;
	lin.sy = p1.y < p2.y ? 1 : -1;
	lin.error = lin.dx - lin.dy;
	return (lin);
}

void			ft_draw_line(t_e *all, t_p p1, t_p p2)
{
	t_lin	lin;
	int		x1;
	int		y1;

	x1 = p1.x;
	y1 = p1.y;
	lin = line_init(p1, p2);
	while (x1 != p2.x || y1 != p2.y)
	{
		ft_img_px_put(all, x1, y1, 0xFFFFFF);
		lin.error2 = lin.error * 2;
		if (lin.error2 > -lin.dy)
		{
			lin.error -= lin.dy;
			x1 += lin.sx;
		}
		if (lin.error2 < lin.dx)
		{
			lin.error += lin.dx;
			y1 += lin.sy;
		}
	}
}

t_p				point_in(int x, int y)
{
	t_p		p;

	p.x = x;
	p.y = y;
	return (p);
}

static void		draw_segment(t_e *e, int iter, t_p p1, t_p p2)
{
	t_p		dist;
	t_p		p_a;
	t_p		p_b;
	t_p		p_tip;
	double	sin60;

	if (iter == 0)
		ft_draw_line(e, p1, p2);
	if (iter >= 1)
	{
		dist = point_in((p2.x - p1.x) / 3, (p2.y - p1.y) / 3);
		p_a = point_in(p1.x + dist.x, p1.y + dist.y);
		p_b = point_in(p2.x - dist.x, p2.y - dist.y);
		sin60 = -0.866025403784438646763723170752936183471402626905190;
		p_tip = point_in(p_a.x + (int)(dist.x * 0.5 + dist.y * sin60),
				p_a.y + (int)(dist.y * 0.5 - dist.x * sin60));
		draw_segment(e, iter - 1, p1, p_a);
		draw_segment(e, iter - 1, p_a, p_tip);
		draw_segment(e, iter - 1, p_tip, p_b);
		draw_segment(e, iter - 1, p_b, p2);
	}
}

void			ft_koch(t_e *e)
{
	t_p		p1;
	t_p		p2;
	t_p		p3;

	p1 = point_in(((0.) * e->width * e->zo) / 4 +
			(e->width / 2) - (e->x_sh * e->width * e->zo) / 4,
			((-0.5) * e->height * e->zo) / 4 +
			(e->height / 2) - (e->y_sh * e->height * e->zo) / 4);
	p2 = point_in(((-0.5) * e->width * e->zo) / 4 +
			(e->width / 2) - (e->x_sh * e->width * e->zo) / 4,
			((0.5) * e->height * e->zo) / 4 +
			(e->height / 2) - (e->y_sh * e->height * e->zo) / 4);
	p3 = point_in(((0.5) * e->width * e->zo) / 4 +
			(e->width / 2) - (e->x_sh * e->width * e->zo) / 4,
			((0.5) * e->height * e->zo) / 4 +
			(e->height / 2) - (e->y_sh * e->height * e->zo) / 4);
	draw_segment(e, 10, p1, p2);
	draw_segment(e, 10, p2, p3);
	draw_segment(e, 10, p3, p1);
	ft_img_px_put(e, e->width / 2, e->height / 2, 0xffffff);
}
