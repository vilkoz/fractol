/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:26:45 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/09 20:34:44 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	keys_init(t_k *k)
{
	k->zoom = 0;
	k->x_sh = 0;
	k->y_sh = 0;
}

void	ft_zoom(t_e *e, int sign)
{
	if (e->x_sh < 0 && e->y_sh < 0)
	{
		e->zo -= sign * 0.05;
	}
}

int		key_press(int key, t_e *e)
{
	(key == 53) ? exit(0) : (void)e->k.gopa;
	(key == 29) ? e->x_sh = 0, e->y_sh = 0 : (void)e->k.gopa;
	(key == 123) ? e->k.x_sh = -1 : (void)e->k.gopa; 
	(key == 124) ? e->k.x_sh = 1 : (void)e->k.gopa; 
	(key == 125) ? e->k.y_sh = -1 : (void)e->k.gopa; 
	(key == 126) ? e->k.y_sh = 1 : (void)e->k.gopa; 
	(key == 27) ? e->k.zoom = 1 : (void)e->k.gopa; 
	(key == 24) ? e->k.zoom = -1 : (void)e->k.gopa; 
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
	return (0);
}

int		loop_hook(t_e *e)
{
	(e->k.x_sh == 1) ? e->x_sh += 0.1 : (void)e->k.gopa;
	(e->k.x_sh == -1) ? e->x_sh -= 0.1 : (void)e->k.gopa;
	(e->k.y_sh == 1) ? e->y_sh -= 0.1 : (void)e->k.gopa;
	(e->k.y_sh == -1) ? e->y_sh += 0.1 : (void)e->k.gopa;
	(e->k.zoom == 1) ? e->zo *= 1.1 : (void)e->k.gopa;
	(e->k.zoom == -1) ? e->zo /= 1.1 : (void)e->k.gopa;
	if (e->k.m_zo == 1)
	{
		e->zo *= 1.1;
		e->x_sh = e->m_x;
		e->y_sh = e->m_y;
		e->k.m_zo = 0;
	}
	if (e->k.m_zo == -1)
	{
		e->zo /= 1.1;
		e->x_sh = e->m_x;
		e->y_sh = e->m_y;
		e->k.m_zo = 0;
	}
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	ft_mundel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_put_info(e);
	return (0);
}

int		mouse_hook(int	key, int x, int y, t_e *e)
{
	(void)x;
	(void)y;
	if (key == 5)
	{
		e->k.m_zo = + 1;
		/*
		e->m_x = (x * 1. - e->width / 2)  * 4 / (e->width * e->zo) + e->x_sh;
		e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
		*/
	}
	if (key == 4)
	{
		e->k.m_zo = - 1;
		/*
		e->m_x = (x * 1. - e->width / 2)  * 4 / (e->width * e->zo) + e->x_sh;
		e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
		*/
	}
	return (0);
}

int		move_hook(int x, int y, t_e *e)
{
	e->m_x = (x * 1. - e->width / 2)  * 4 / (e->width * e->zo) + e->x_sh;
	e->m_y = (y * 1. - e->height / 2) * 4 / (e->height * e->zo) + e->y_sh;
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
