/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:15:47 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/07 18:26:41 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		main(int argc, char **argv)
{
	t_e		*e;

	e = ft_mlx_init("test");
	ft_mundel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_loop(e->mlx);
	return (0);
}
