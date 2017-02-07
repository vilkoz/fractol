/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:16:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/07 21:51:31 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACT_H
# define _FRACT_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct	s_e
{
	void		*mlx;
	void		*win;
	void		*img;
	int			height;
	int			width;
	int			max;
	int			*colors;
	double		c_re;
	double		c_im;
	double		x;
	double		x_new;
	double		y;
	int			iter;
	int			zo;
	int			x_sh;
	int			y_sh;
}				t_e;

t_e				*ft_mlx_init(char *s);
void			ft_img_px_put(t_e *e, int x, int y, int rgb);
void			ft_mundel(t_e *e);

#endif
