/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mundel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:35:28 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/01 01:24:38 by vrybalko         ###   ########.fr       */
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

static void		ft_iterate(t_e *e, t_slice *s)
{
	while (s->x * s->x + s->y * s->y < 4 && s->iter < e->max)
	{
		s->x_2 = s->x * s->x - s->y * s->y + s->c_re;
		s->y = 2 * s->x * s->y + s->c_im;
		s->x = s->x_2;
		s->iter++;
	}
}

static void		ft_three(t_e *e, int j, int i, t_slice *s)
{
	if (e->k.tr_d == 1 && j % 5 == 0 && i % 5 == 0)
	{
		e->lst = (s->iter < e->max) ? ft_lst_add(e->lst, ft_lst_new(j, i,
			s->iter, e->colors[s->iter] + e->r_sh)) :
			ft_lst_add(e->lst, ft_lst_new(j, i, s->iter,
						e->colors[s->iter] + e->r_sh));
	}
	else if (e->k.tr_d != 1)
		(s->iter < e->max) ? ft_img_px_put(e, j, i, e->colors[s->iter] +
				e->r_sh) : ft_img_px_put(e, j, i, 0);
}

//void			ft_mundel(t_e *e)
//{
//	int		i;
//	int		j;
//
//	i = -1;
//	e->colors = init_colors(e);
//	while (++i < e->height)
//	{
//		j = -1;
//		while (++j < e->width)
//		{
//			e->c_re = ((j - e->width / 2) * 4. + (e->width * 1.)
//					* e->x_sh * e->zo) / (e->width * e->zo);
//			e->c_im = ((i - e->height / 2) * 4. + (e->height * 1.)
//					* e->y_sh * e->zo) / (e->height * e->zo);
//			e->x = 0;
//			e->y = 0;
//			e->iter = 0;
//			ft_iterate(e);
//			ft_three(e, j, i);
//		}
//	}
//	ft_img_px_put(e, e->width / 2, e->height / 2, 0xFFFFFF);
//}

void			*ft_mundel_slice(void *a)
{
	t_slice		*s;
	t_e			*e;
	int			i;
	int			j;

	s = (t_slice *)a;
	e = s->e;
	i = s->y_start - 1;
	while (++i < s->y_end)
	{
		j = -1;
		while (++j < e->width)
		{
			s->c_re = ((j - e->width / 2) * 4. + (e->width * 1.)
					* e->x_sh * e->zo) / (e->width * e->zo);
			s->c_im = ((i - e->height / 2) * 4. + (e->height * 1.)
					* e->y_sh * e->zo) / (e->height * e->zo);
			s->x = 0;
			s->y = 0;
			s->iter = 0;
			ft_iterate(e, s);
			ft_three(e, j, i, s);
		}
	}
	return (0);
}

void			ft_mundel(t_e *e)
{
	t_slice		s[THREAD_NUM];
	int			i;
	int			y;
	int			dy;

	dy = e->height / THREAD_NUM;
	y = 0;
	i = -1;
	e->colors = init_colors(e);
	while (++i < THREAD_NUM)
	{
		s[i].y_start = y;
		s[i].y_end = y + dy;
		s[i].e = e;
		pthread_create(&(s[i].id), NULL, ft_mundel_slice, s + i);
		y += dy;
	}
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(s[i].id, NULL);
}
