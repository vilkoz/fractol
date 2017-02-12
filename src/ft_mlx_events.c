/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:26:45 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/12 20:49:56 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	keys_init(t_k *k)
{
	k->zoom = 0;
	k->x_sh = 0;
	k->y_sh = 0;
	k->m_co = 1;
	k->tr_d = 0;
}

void	ft_mzoom(t_e *e)
{
	if (e->k.m_zo == 1 && e->f_type != 4)
	{
		e->zo *= 1.1;
		e->x_sh = e->m_x - (e->m_dx * 4) / (e->width * e->zo);
		e->y_sh = e->m_y - (e->m_dy * 4) / (e->height * e->zo);
	}
	if (e->k.m_zo == -1 && e->f_type != 4)
	{
		e->zo /= 1.1;
		e->x_sh = e->m_x - (e->m_dx * 4) / (e->width * e->zo);
		e->y_sh = e->m_y - (e->m_dy * 4) / (e->height * e->zo);
	}
	if (e->k.m_zo == 1 && e->f_type == 4)
	{
		e->zo *= 1.1;
		e->x_sh = e->m_x - e->width / 2;
		e->y_sh = e->m_y - e->height / 2;
	}
	if (e->k.m_zo == -1 && e->f_type == 4)
	{
		e->zo /= 1.1;
		e->x_sh = e->m_x - e->width / 2;
		e->y_sh = e->m_y - e->height / 2;
	}
		e->k.m_zo = 0;
}

void	ft_frac_switch(t_e *e)
{
	e->f_type += 1;
	if (e->f_type > 4)
		e->f_type = 0;
}

void	ft_fract_ch(t_e *e)
{
	if (e->f_type == 0)
		ft_julia(e);
	if (e->f_type == 1)
		ft_mundel(e);
	if (e->f_type == 2)
		ft_burning(e);
	if (e->f_type == 3)
		ft_sinusoidal(e);
	if (e->f_type == 4)
		ft_koch(e);
}

void	ft_i_max_chan(t_e *e, char sign)
{
	if (sign == '-')
		e->max = (e->max - 10 <= 30) ? 30 : e->max - 10;
	if (sign == '+')
		e->max += 10;
}

void	ft_tr_d_switch(t_e *e)
{
	if (e->k.tr_d == 0)
		e->k.tr_d = 1;
	else if (e->k.tr_d == 1)
		e->k.tr_d = 0;
}

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
	ft_fract_ch(e);
	(e->k.tr_d == 1) ? e = ft_view(e) : (void)e->k.gopa;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_put_info(e);
	return (0);
}

int		mouse_hook(int key, int x, int y, t_e *e)
{
	if (key == 5 && e->f_type != 4)
	{
		e->k.m_zo = +1;
		e->m_x = (x * 1. - e->width / 2) * 4 / (e->width * e->zo) + e->x_sh;
		e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
		e->m_dx = (x * 1. - e->width / 2);
		e->m_dy = (y * 1. - e->height / 2);
	}
	if (key == 4 && e->f_type != 4)
	{
		e->k.m_zo = -1;
		e->m_x = (x * 1. - e->width / 2) * 4 / (e->width * e->zo) + e->x_sh;
		e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
		e->m_dx = (x * 1. - e->width / 2);
		e->m_dy = (y * 1. - e->height / 2);
	}
	if (key == 5 && e->f_type == 4)
	{
		e->k.m_zo = +1;
		e->m_x = x; 
		e->m_y = y; 
	}
	if (key == 4 && e->f_type == 4)
	{
		e->k.m_zo = -1;
		e->m_x = x; 
		e->m_y = y; 
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

void	ft_mlx_events(t_e *e)
{
	keys_init(&(e->k));
	mlx_hook(e->win, 2, 1, key_press, e);
	mlx_hook(e->win, 3, 2, key_release, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, 65, move_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}
