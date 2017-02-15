/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_koch_quad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:54:13 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/15 20:46:18 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_p		tip_return(t_p p1,	t_p p2, t_p p3, t_p dist)
{
	t_p		p_tip;

	p_tip = point_in((dist.x == 0) ?
		(p2.y > p1.y ? p1.x - 3 * dist.y / 3 : p1.x - 3 * dist.y / 3 ) : p3.x,
		(dist.y == 0) ? (p2.x > p1.x ? p1.y - 3 * dist.x / 3 :
		p1.y + 3 * dist.x / 3 ) : p3.y);
	return (p_tip);
}

static void		draw_segment(t_e *e, int iter, t_p p1, t_p p2)
{
	t_p		dist;
	t_p		p_a;
	t_p		p_b;
	t_p		p_tip1;
	t_p		p_tip2;

	if (iter == 0)
		ft_draw_line(e, p1, p2);
	if (iter >= 1)
	{
		dist = point_in((p2.x - p1.x) / 3, (p2.y - p1.y) / 3);
		p_a = point_in(p1.x + dist.x, p1.y + dist.y);
		p_b = point_in(p2.x - dist.x, p2.y - dist.y);
		p_tip1 = tip_return(p1, p2, p_a, dist);
		p_tip2 = tip_return(p1, p2, p_b, dist);
		draw_segment(e, iter - 1, p1, p_a);
		draw_segment(e, iter - 1, p_a, p_tip1);
		draw_segment(e, iter - 1, p_tip1, p_tip2);
		draw_segment(e, iter - 1, p_tip2, p_b);
		draw_segment(e, iter - 1, p_b, p2);
	}
}

void	ft_koch_quad(t_e *e)
{
	t_p		p1;
	t_p		p2;

	p1 = point_in(((-0.5) * e->width * e->zo) / 4 +
			(e->width / 2) - (e->x_sh * e->width * e->zo) / 4,
			((0) * e->height * e->zo) / 4 +
			(e->height / 2) - (e->y_sh * e->height * e->zo) / 4);
	p2 = point_in(((0.5) * e->width * e->zo) / 4 +
			(e->width / 2) - (e->x_sh * e->width * e->zo) / 4,
			((0) * e->height * e->zo) / 4 +
			(e->height / 2) - (e->y_sh * e->height * e->zo) / 4);
	draw_segment(e, e->max / 10 + 3, p1, p2);
}
