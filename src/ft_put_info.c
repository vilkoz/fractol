/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:26:17 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/09 20:34:48 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		ft_putstry(t_e *e, char *str)
{
	e->txt_shift += 15;
	mlx_string_put(e->mlx, e->win, 15, e->txt_shift, 0xffffff, str);
}


void		ft_put_info(t_e *e)
{
	ft_putstry(e, ft_strjoin("Zoom: ", ft_itoa((int)(e->zo * 1000))));
	ft_putstry(e, ft_strjoin("x shift: ", ft_itoa(e->x_sh * 1000)));
	ft_putstry(e, ft_strjoin("y shift: ", ft_itoa(e->y_sh * 1000)));
	ft_putstry(e, ft_strjoin("x mouse: ", ft_itoa(e->m_x * 1000)));
	ft_putstry(e, ft_strjoin("y mouse: ", ft_itoa(e->m_y * 1000)));
	e->txt_shift = 0;
}
