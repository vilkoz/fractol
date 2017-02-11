/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:39:57 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/11 20:54:55 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		ft_iso(t_e *all, int *x, int *y, int *z)
{
	int		x1;
	int		y1;
	int		z1;

	x1 = *x - (all->width / 2);
	y1 = *y - (all->height / 2);
	z1 = -(*z);
	*x = (x1 * cos(70.5 * RAD) + (-y1 * sin(90 * RAD) + z1 * cos(90 * RAD))
		* sin(70.5 * RAD)) * cos(-60 * RAD) + (y1 * cos(90 * RAD)
		+ z1 * sin(90 * RAD)) * sin(-60 * RAD) + (all->width / 2);
	*y = -(x1 * cos(70.5 * RAD) + (-y1 * sin(90 * RAD) + z1 * cos(90 * RAD))
		* sin(70.5 * RAD)) * sin(-60 * RAD) + (y1 * cos(90 * RAD)
		+ z1 * sin(90 * RAD)) * cos(-60 * RAD) + (all->height / 2);
}

t_lst		*ft_lst_new(int x, int y, int z, int rgb)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->x = x;
	new->y = y;
	new->z = z;
	new->rgb = rgb;
	return (new);
}

t_lst		*ft_lst_add(t_lst *new, t_lst *old)
{
	if (new != NULL)
		new->next = old;
	return (old);
}

void		ft_putpixels(t_e *e)
{
	t_lst	*tmp;

	tmp = e->lst;
	while (tmp)
	{
		ft_img_px_put(e, tmp->x, tmp->y, tmp->rgb);
		tmp = tmp->next;
	}
}

void		ft_view(t_e *all)
{
	t_lst	*tmp;
	t_lst	*head;

	tmp = all->lst;
	head = tmp;
	while (tmp)
	{
		tmp->x *= 10;
		tmp->y *= 10;
		ft_iso(all, &(tmp->x), &(tmp->y), &(tmp->z));
		tmp = tmp->next;
	}
	all->lst = head;
	ft_putpixels(all);
}
