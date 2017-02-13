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
	ft_putstr_fd(" burning | sinusoidal>\n", 2);
	return (0);
}

int			ft_arg_check(char *argv, t_e *e)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		e = ft_mlx_init("Fractol", 1, e);
	else if (ft_strcmp(argv, "julia") == 0)
		e = ft_mlx_init("Fractol", 0, e);
	else if (ft_strcmp(argv, "burning") == 0)
		e = ft_mlx_init("Fractol", 2, e);
	else if (ft_strcmp(argv, "sinusoidal") == 0)
		e = ft_mlx_init("Fractol", 3, e);
	else if (ft_strcmp(argv, "koch") == 0)
		e = ft_mlx_init("Fractol", 4, e);
	else
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_e		e;
	t_e		e1;

	e.mlx = NULL;
	if (argc < 2 || argc > 3)
		return (ft_putusage());
	if (argc == 2)
	{
		if (ft_arg_check(argv[1], &e) == -1)
			return (ft_putusage());
		ft_mlx_events(&e);
		mlx_loop(e.mlx);
	}
	else
	{
		if (ft_arg_check(argv[1], &e) == -1)
			return (ft_putusage());
		e1.mlx = e.mlx;
		if (ft_arg_check(argv[2], &e1) == -1)
			return (ft_putusage());
		ft_mlx_events(&e);
		ft_mlx_events(&e1);
		mlx_loop(e.mlx);
	}
	return (0);
}
