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

void	ft_tr_d_switch(t_e *e)
{
	if (e->k.tr_d == 0)
		e->k.tr_d = 1;
	else if (e->k.tr_d == 1)
		e->k.tr_d = 0;
}

void	ft_mlx_events(t_e *e)
{
	keys_init(&(e->k));
	mlx_hook(e->win, 2, 1, key_press, e);
	mlx_hook(e->win, 3, 2, key_release, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, 65, move_hook, e);
}
