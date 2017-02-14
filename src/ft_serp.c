/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:39:13 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/14 18:19:41 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_tr	triangle_in(t_p p1, t_p p2, t_p p3)
{
	t_tr	tr;

	tr.p1 = p1;
	tr.p2 = p2;
	tr.p3 = p3;
	return (tr);
}

t_p		find_mid(t_p p1, t_p p2)
{
	t_p		res;

	res.x = round((p1.x + p2.x) / 2);
	res.y = round((p1.y + p2.y) / 2);
	return (res);
}

void	draw_triangle(t_e *e, int iter, t_tr tr)
{
	t_tr	c;

	if (iter > 0)
	{
		ft_draw_line(e, tr.p1, tr.p2);
		ft_draw_line(e, tr.p1, tr.p3);
		ft_draw_line(e, tr.p3, tr.p2);
		c = triangle_in(find_mid(tr.p1, tr.p2), find_mid(tr.p2, tr.p3),
				find_mid(tr.p3, tr.p1));
		ft_draw_line(e, c.p1, c.p2);
		ft_draw_line(e, c.p1, c.p3);
		ft_draw_line(e, c.p3, c.p2);
		draw_triangle(e, iter - 1, triangle_in(tr.p1, c.p1, c.p3));
		draw_triangle(e, iter - 1, triangle_in(tr.p2, c.p1, c.p2));
		draw_triangle(e, iter - 1, triangle_in(tr.p3, c.p2, c.p3));
	}
}

void	ft_serp(t_e *e)
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
	draw_triangle(e, 10, triangle_in(p1, p2, p3));
}
