/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:39:57 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/14 17:14:42 by vrybalko         ###   ########.fr       */
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
	*x = (x1 * cos(B) + (-y1 * sin(A) + z1 * cos(A))
		* sin(B)) * cos(G) + (y1 * cos(A)
		+ z1 * sin(A)) * sin(G) + (all->width / 2);
	*y = -(x1 * cos(B) + (-y1 * sin(A) + z1 * cos(A))
		* sin(B)) * sin(G) + (y1 * cos(A)
		+ z1 * sin(A)) * cos(G) + (all->height / 2);
}

t_lst			*ft_lst_new(int x, int y, int z, int rgb)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->x = x;
	new->x1 = x;
	new->y = y;
	new->y1 = y;
	new->z = z;
	new->z1 = z;
	new->rgb = rgb;
	return (new);
}

t_lst			*ft_lst_add(t_lst *old, t_lst *new)
{
	if (new != NULL)
		new->next = old;
	return (new);
}

void			ft_putpixels(t_e *e)
{
	t_lst	*tmp;

	tmp = e->lst;
	while (tmp)
	{
		ft_img_px_put(e, tmp->x1, tmp->y1, tmp->rgb);
		tmp = tmp->next;
	}
	e->lst = NULL;
}

t_e				*ft_view(t_e *all)
{
	t_lst	*tmp;
	t_lst	*head;

	tmp = all->lst;
	head = tmp;
	while (tmp)
	{
		tmp->x1 = tmp->x;
		tmp->y1 = tmp->y;
		tmp->z1 = tmp->z;
		ft_iso(all, &(tmp->x1), &(tmp->y1), &(tmp->z1));
		tmp = tmp->next;
	}
	all->lst = head;
	ft_putpixels(all);
	return (all);
}
