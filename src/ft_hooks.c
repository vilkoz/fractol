/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:13:21 by vrybalko          #+#    #+#             */
/*   Updated: 2017/07/07 23:54:45 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		key_press(int key, t_e *e)
{
	(key == 53) ? exit(0) : (void)e->k.gopa;
	(key == 20) ? ft_tr_d_switch(e) : (void)e->k.gopa;
	(key == 29) ? e->x_sh = 0 : (void)e->k.gopa;
	(key == 29) ? e->y_sh = 0 : (void)e->k.gopa;
	(key == 25) ? e->zo = 1 : (void)e->k.gopa;
	(key == 123) ? e->k.x_sh = -1 : (void)e->k.gopa;
	(key == 124) ? e->k.x_sh = 1 : (void)e->k.gopa;
	(key == 125) ? e->k.y_sh = -1 : (void)e->k.gopa;
	(key == 126) ? e->k.y_sh = 1 : (void)e->k.gopa;
	(key == 27) ? e->k.zoom = 1 : (void)e->k.gopa;
	(key == 24) ? e->k.zoom = -1 : (void)e->k.gopa;
	if (key == 46)
		e->k.m_co = (e->k.m_co == 1) ? 0 : 1;
	(key == 15) ? e->k.r_sh = 1 : (void)e->k.gopa;
	(key == 5) ? e->k.g_sh = 1 : (void)e->k.gopa;
	(key == 11) ? e->k.b_sh = 1 : (void)e->k.gopa;
	return (0);
}

int		key_release(int key, t_e *e)
{
	(key == 123) ? e->k.x_sh = 0 : (void)e->k.gopa;
	(key == 124) ? e->k.x_sh = 0 : (void)e->k.gopa;
	(key == 125) ? e->k.y_sh = 0 : (void)e->k.gopa;
	(key == 126) ? e->k.y_sh = 0 : (void)e->k.gopa;
	(key == 27) ? e->k.zoom = 0 : (void)e->k.gopa;
	(key == 24) ? e->k.zoom = 0 : (void)e->k.gopa;
	(key == 3) ? ft_frac_switch(e) : (void)e->k.gopa;
	(key == 30) ? ft_i_max_chan(e, '-') : (void)e->k.gopa;
	(key == 33) ? ft_i_max_chan(e, '+') : (void)e->k.gopa;
	(key == 15) ? e->k.r_sh = 0 : (void)e->k.gopa;
	(key == 5) ? e->k.g_sh = 0 : (void)e->k.gopa;
	(key == 11) ? e->k.b_sh = 0 : (void)e->k.gopa;
	return (0);
}

int		loop_hook(t_e *e)
{
	clock_t		time;

	(e->k.x_sh == 1) ? e->x_sh += 0.1 / e->zo : (void)e->k.gopa;
	(e->k.x_sh == -1) ? e->x_sh -= 0.1 / e->zo : (void)e->k.gopa;
	(e->k.y_sh == 1) ? e->y_sh -= 0.1 / e->zo : (void)e->k.gopa;
	(e->k.y_sh == -1) ? e->y_sh += 0.1 / e->zo : (void)e->k.gopa;
	(e->k.zoom == 1) ? e->zo /= 1.1 : (void)e->k.gopa;
	(e->k.zoom == -1) ? e->zo *= 1.1 : (void)e->k.gopa;
	(e->k.m_zo == -1 || e->k.m_zo == 1) ? ft_mzoom(e) : (void)e->k.gopa;
	(e->k.r_sh == 1) ? e->r_sh += 0x110000 : (void)e->k.gopa;
	(e->k.g_sh == 1) ? e->r_sh += 0x1100 : (void)e->k.gopa;
	(e->k.b_sh == 1) ? e->r_sh += 0x11 : (void)e->k.gopa;
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	time = clock();
	ft_fract_ch(e);
	e->time = clock() - time;
	(e->k.tr_d == 1) ? e = ft_view(e) : (void)e->k.gopa;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	/* ft_put_info(e); */
	return (0);
}

int		mouse_hook(int key, int x, int y, t_e *e)
{
	if (key == 5)
	{
		e->k.m_zo = +1;
		e->m_x = (x * 1. - e->width / 2) * 4 / (e->width * e->zo) + e->x_sh;
		e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
		e->m_dx = (x * 1. - e->width / 2) * 4 / (e->width);
		e->m_dy = (y * 1. - e->height / 2) * 4 / (e->height);
	}
	if (key == 4)
	{
		e->k.m_zo = -1;
		e->m_x = (x * 1. - e->width / 2) * 4 / (e->width * e->zo) + e->x_sh;
		e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
		e->m_dx = (x * 1. - e->width / 2) * 4 / (e->width);
		e->m_dy = (y * 1. - e->height / 2) * 4 / (e->height);
	}
	return (0);
}

int		move_hook(int x, int y, t_e *e)
{
	if (e->f_type == 0 && e->k.m_co)
	{
		e->c_re = (x * 1. - e->width / 2) / e->width + -0.7;
		e->c_im = (y * 1. - e->height / 2) / e->height + 0.27015;
	}
	return (0);
}
