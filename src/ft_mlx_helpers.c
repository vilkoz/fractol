#include "fract.h"

void	keys_init(t_k *k)
{
	k->zoom = 0;
	k->x_sh = 0;
	k->y_sh = 0;
	k->m_co = 1;
	k->tr_d = 0;
	k->r_sh = 0;
	k->g_sh = 0;
	k->b_sh = 0;
	k->m_zo = 0;
}

void	ft_mzoom(t_e *e)
{
	if (e->k.m_zo == 1)
	{
		e->zo *= 1.1;
		e->x_sh = e->m_x - e->m_dx / e->zo;
		e->y_sh = e->m_y - e->m_dy / e->zo;
	}
	if (e->k.m_zo == -1)
	{
		e->zo /= 1.1;
		e->x_sh = e->m_x - e->m_dx / e->zo;
		e->y_sh = e->m_y - e->m_dy / e->zo;
	}
		e->k.m_zo = 0;
}

void	ft_frac_switch(t_e *e)
{
	e->f_type += 1;
	if (e->f_type > 4)
		e->f_type = 0;
}

void	ft_fract_ch(t_e *e)
{
	if (e->f_type == 0)
		ft_julia(e);
	if (e->f_type == 1)
		ft_mundel(e);
	if (e->f_type == 2)
		ft_burning(e);
	if (e->f_type == 3)
		ft_sinusoidal(e);
	if (e->f_type == 4)
		ft_koch(e);
}

void	ft_i_max_chan(t_e *e, char sign)
{
	if (sign == '-')
		e->max = (e->max - 10 <= 30) ? 30 : e->max - 10;
	if (sign == '+')
		e->max += 10;
}

