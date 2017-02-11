/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:25:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/11 18:52:58 by vrybalko         ###   ########.fr       */
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
	e->f_type = type;
	e->c_re = -0.7;
	e->c_im = 0.27015;
	e->r_sh = 0;
	e->lst = NULL;
	return (e);
}
