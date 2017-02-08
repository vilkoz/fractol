/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:26:45 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/08 21:12:03 by vrybalko         ###   ########.fr       */
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
		//e->x_sh -= 50 / e->zo;
		//e->y_sh -= 50 / e->zo;
	}
}

int		key_press(int key, t_e *e)
{
	(key == 53) ? exit(1) : (void)e->k.gopa;
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
	(e->k.x_sh == 1) ? e->x_sh += 100 : (void)e->k.gopa;
	(e->k.x_sh == -1) ? e->x_sh -= 100 : (void)e->k.gopa;
	(e->k.y_sh == 1) ? e->y_sh -= 100 : (void)e->k.gopa;
	(e->k.y_sh == -1) ? e->y_sh += 100 : (void)e->k.gopa;
	(e->k.zoom == 1) ? ft_zoom(e, -1) : (void)e->k.gopa;
	(e->k.zoom == -1) ? ft_zoom(e, 1) : (void)e->k.gopa;
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	ft_mundel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_put_info(e);
	return (0);
}

void	ft_mlx_events(t_e *e)
{
	keys_init(&(e->k));
	mlx_hook(e->win, 2, 1, key_press, e);
	mlx_hook(e->win, 3, 2, key_release, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}
