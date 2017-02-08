/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:25:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/08 21:03:43 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_e		*ft_mlx_init(char *s, int type)
{
	t_e		*e;

	e = (t_e *)malloc(sizeof(t_e));
	e->mlx = mlx_init();
	e->height = 1300;
	e->width = 1300;
	e->x_sh = 0;
	e->y_sh = 0;
	e->zo = 1;
	e->win = mlx_new_window(e->mlx, e->width, e->height, s);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->max = 30;
	e->fract_type = type;
	return (e);
}
