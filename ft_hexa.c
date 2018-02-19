/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 16:45:29 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 14:06:22 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_wp_minus(t_params *f, int i, int l, int j)
{
	int k;

	k = 0;
	if (f->diese_f == 1 && ft_strcmp(f->str_lst, "\0") != 0)
	{
		ft_diese_hexa(f);
		i = (f->type == 'o' || f->type == 'O') ? i + 1 : i + 2;
	}
	k = ft_minus_hexa(f, k);
	if (f->len + i >= f->width)
		ft_putstr_count(f->str_lst, f->scount);
	while (i < l)
	{
		if (f->precision - i == f->len && j != 1)
		{
			ft_putstr_count(f->str_lst, f->scount);
			i--;
			j = 1;
		}
		else if (f->len < f->precision - i)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
}

static void		ft_wp_hexa_boucle(t_params *f, int *tab)
{
	while (tab[0] < tab[3])
	{
		if (f->width - tab[0] == ft_v(f) + tab[2] &&
				(f->diese_f == 1 || f->type == 'p') && tab[1] != 1)
		{
			ft_diese_hexa(f);
			tab[0] = (f->type == 'o' || f->type == 'O') ? tab[0] : tab[0] + 1;
		}
		else if (f->width - tab[0] > f->precision + tab[2])
			write_count(1, " ", 1, f->scount);
		else
			write_count(1, "0", 1, f->scount);
		tab[0]++;
	}
}

void			ft_wp_hexa(t_params *f, int i, int l, int j)
{
	int k;
	int	params[4];

	k = 0;
	if (f->diese_f == 1 && (f->type == 'o' || f->type == 'o'))
		k = 1;
	if (f->diese_f == 1 && (f->type != 'o' && f->type != 'O'))
		k = 2;
	if ((f->len + k + f->precision >= f->width || f->zero_f == 1) &&
			(f->diese_f == 1 || f->type == 'p'))
	{
		ft_diese_hexa(f);
		i = (f->type == 'o' || f->type == 'O') ? i + 1 : i + 2;
		if (f->precision + 1 == f->width && f->type != 'o' && f->type != 'O')
			i--;
		j = 1;
	}
	k = ft_minus_hexa(f, k);
	params[0] = i;
	params[1] = j;
	params[2] = k;
	params[3] = l;
	ft_wp_hexa_boucle(f, params);
}

static	void	ft_width_hexa_boucle(t_params *f, int *tab)
{
	while (tab[0] < tab[3])
	{
		if (f->width - tab[0] == f->len + tab[2] &&
				(f->diese_f == 1 || f->type == 'p')
				&& tab[1] != 1)
		{
			ft_diese_hexa(f);
			tab[1] = 1;
			(f->type == 'o' || f->type == 'O') ? tab[0] : tab[0]++;
		}
		else if (f->zero_f == 1 && f->moins_f == 0 && f->precision == -1)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		tab[0]++;
	}
}

void			ft_width_hexa(t_params *f, int i, int l, int j)
{
	int k;
	int params[4];

	k = 0;
	if ((ft_strcmp(f->str_lst, "0") != 0 && ft_strcmp(f->str_lst, "\0"))
			!= 0 || f->type == 'p')
	{
		if (f->len < f->width && f->moins_f == 0 && f->precision == 0)
			k = 0;
		else if ((l < 0 || f->zero_f == 1 || f->moins_f == 1)
				&& (f->diese_f == 1 || f->type == 'p'))
		{
			ft_diese_hexa(f);
			i = (f->type == 'o' || f->type == 'O') ? i + 1 : i + 2;
			j = 1;
		}
		k = ft_minus_hexa(f, k);
	}
	params[0] = i;
	params[1] = j;
	params[2] = k;
	params[3] = l;
	ft_width_hexa_boucle(f, params);
}
