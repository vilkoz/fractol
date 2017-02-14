/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:15:47 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/14 18:12:42 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	ft_putusage(int type)
{
	if (type == USAGE_MSG)
	{
		ft_putstr_fd("usage: ./fractol <mandelbrot | julia |", 2);
		ft_putstr_fd(" burning | sinusoidal | koch | sierpinski>\n", 2);
	}
	if (type == FRACT_LST)
	{
		ft_putstr_fd("Error: wrong argument!\nAvalible fractals:\n", 2);
		ft_putstr_fd("\tmandelbrot\n\tjulia\n\tburning\n", 2);
		ft_putstr_fd("\tsinusoidal\n\tkoch\n\tsierpinski\t", 2);
	}
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
	else if (ft_strcmp(argv, "sierpinski") == 0)
		e = ft_mlx_init("Fractol", 5, e);
	else
		return (-1);
	return (0);
}

int			loop_fortwo(t_e2 *n)
{
	loop_hook(&(n->e));
	loop_hook(&(n->e1));
	return (0);
}

int			two_args_mode(t_e2 n, char **argv)
{
	if (ft_arg_check(argv[1], &(n.e)) == -1)
		return (ft_putusage(FRACT_LST));
	n.e1.mlx = n.e.mlx;
	if (ft_arg_check(argv[2], &(n.e1)) == -1)
		return (ft_putusage(FRACT_LST));
	ft_mlx_events(&(n.e));
	ft_mlx_events(&(n.e1));
	mlx_loop_hook(n.e.mlx, loop_fortwo, &n);
	mlx_loop(n.e.mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_e2	n;

	n.e.mlx = NULL;
	if (argc < 2 || argc > 3)
		return (ft_putusage(USAGE_MSG));
	if (argc == 2)
	{
		if (ft_arg_check(argv[1], &(n.e)) == -1)
			return (ft_putusage(FRACT_LST));
		ft_mlx_events(&(n.e));
		mlx_loop_hook(n.e.mlx, loop_hook, &(n.e));
		mlx_loop(n.e.mlx);
	}
	else
		return (two_args_mode(n, argv));
	return (0);
}
