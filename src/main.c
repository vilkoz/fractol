/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:15:47 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/12 19:46:51 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	ft_putusage(void)
{
	ft_putstr_fd("usage: ./fractol <mandelbrot | julia |", 2);
	ft_putstr_fd(" burning | sinusoidal >\n", 2);
	return (0);
}

int			main(int argc, char **argv)
{
	t_e		*e;

	e = NULL;
	if (argc != 2)
		return (ft_putusage());
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		e = ft_mlx_init("test", 1);
	else if (ft_strcmp(argv[1], "julia") == 0)
		e = ft_mlx_init("test", 0);
	else if (ft_strcmp(argv[1], "burning") == 0)
		e = ft_mlx_init("test", 2);
	else if (ft_strcmp(argv[1], "sinusoidal") == 0)
		e = ft_mlx_init("test", 3);
	else if (ft_strcmp(argv[1], "koch") == 0)
		e = ft_mlx_init("test", 4);
	else
		return (ft_putusage());
	ft_mlx_events(e);
	return (0);
}
