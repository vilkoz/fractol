/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:16:07 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/09 20:34:43 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACT_H
# define _FRACT_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>

/*
** struct for key events
*/

typedef struct	s_k
{
	int			zoom;
	int			x_sh;
	int			y_sh;
	int			m_zo;
	int			gopa;
}				t_k;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

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
	double		x_2;
	double		y_2;
	double		x_new;
	double		y;
	int			iter;
	double		zo;
	double		x_sh;
	double		y_sh;
	t_k			k;
	int			fract_type;
	int			txt_shift;
	double		m_x;
	double		m_dx;
	double		m_dy;
	double		m_y;
}				t_e;


t_e				*ft_mlx_init(char *s, int type);
void			ft_img_px_put(t_e *e, int x, int y, int rgb);
void			ft_mundel(t_e *e);
void			ft_mlx_events(t_e *e);
void			ft_put_info(t_e *e);

#endif
