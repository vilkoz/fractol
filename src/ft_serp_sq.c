/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serp_sq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:35:08 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/14 21:41:53 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_sq	square_in(t_p p1, t_p p2, t_p p3, t_p p4)
{
	t_sq	sq;

	sq.p1 = p1;
	sq.p2 = p2;
	sq.p3 = p3;
	sq.p4 = p4;
	return (sq);
}

t_sq	find_subsq(t_sq sq)
{
	t_sq	sub;

	sub.p1.x = sq.p1.x + round((-sq.p1.x + sq.p4.x) / 3);
	sub.p1.y = sq.p1.y + round((-sq.p1.y + sq.p2.y) / 3);
	sub.p2.x = sq.p1.x + round((-sq.p1.x + sq.p4.x) / 3);
	sub.p2.y = sq.p1.y + round(2 * (-sq.p1.y + sq.p2.y) / 3);
	sub.p3.x = sq.p1.x + round(2 * (-sq.p1.x + sq.p4.x) / 3);
	sub.p3.y = sq.p1.y + round(2 * (-sq.p1.y + sq.p2.y) / 3);
	sub.p4.x = sq.p1.x + round(2 * (-sq.p1.x + sq.p4.x) / 3);
	sub.p4.y = sq.p1.y + round((-sq.p1.y + sq.p2.y) / 3);
	return (sub);
}

void	put_square(t_e *e, t_sq sq)
{
	ft_draw_line(e, sq.p1, sq.p2);
	ft_draw_line(e, sq.p1, sq.p4);
	ft_draw_line(e, sq.p2, sq.p3);
	ft_draw_line(e, sq.p4, sq.p3);
}

void	draw_square(t_e *e, int iter, t_sq sq)
{
	t_sq	sub;

	if (iter > 0)
	{
		sub = find_subsq(sq);
		put_square(e, sub);
		draw_square(e, iter - 1, square_in(sq.p1, point_in(sq.p1.x, sub.p1.y),
					sub.p1, point_in(sub.p1.x, sq.p1.y)));
		draw_square(e, iter - 1, square_in(point_in(sub.p1.x, sq.p1.y), sub.p1,
					sub.p4, point_in(sub.p4.x, sq.p1.y)));
		draw_square(e, iter - 1, square_in(point_in(sub.p4.x, sq.p1.y), sub.p4,
					point_in(sq.p4.x, sub.p4.y), sq.p4));
		draw_square(e, iter - 1, square_in(point_in(sq.p1.x, sub.p1.y),
					point_in(sq.p1.x, sub.p2.y), sub.p2, sub.p1));
		draw_square(e, iter - 1, square_in(sub.p4, sub.p3,
					point_in(sq.p4.x, sub.p2.y), point_in(sq.p4.x, sub.p1.y)));
		draw_square(e, iter - 1, square_in(point_in(sq.p1.x, sub.p2.y), sq.p2,
					point_in(sub.p1.x, sq.p2.y), sub.p2));
		draw_square(e, iter - 1, square_in(sub.p2, point_in(sub.p1.x, sq.p2.y),
					point_in(sub.p4.x, sq.p2.y), sub.p3));
		draw_square(e, iter - 1, square_in(sub.p3, point_in(sub.p4.x, sq.p2.y),
					sq.p3, point_in(sq.p4.x, sub.p2.y)));
	}
}

void	ft_serp_sq(t_e *e)
{
	t_p		p1;
	t_p		p2;
	t_p		p3;
	t_p		p4;

	p1 = point_in(((-0.5) * e->width * e->zo) / 4 +
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
	p4 = point_in(((0.5) * e->width * e->zo) / 4 +
			(e->width / 2) - (e->x_sh * e->width * e->zo) / 4,
			((-0.5) * e->height * e->zo) / 4 +
			(e->height / 2) - (e->y_sh * e->height * e->zo) / 4);
	put_square(e, square_in(p1, p2, p3, p4));
	draw_square(e, 6, square_in(p1, p2, p3, p4));
}
