/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 16:45:29 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 23:11:55 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_wp_minus_u(t_params *f, int i, int l)
{
	int j;

	j = 0;
	if (f->moins_f == 1 && f->precision == -1)
		ft_putstr_count(f->str_lst, f->scount);
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

static	void	ft_wp_u(t_params *f, int i, int l)
{
	if (f->moins_f == 1 && f->precision == -1)
		ft_putstr_count(f->str_lst, f->scount);
	while (i < l)
	{
		if (f->width - i > f->precision)
			write_count(1, " ", 1, f->scount);
		else
			write_count(1, "0", 1, f->scount);
		i++;
	}
}

static	void	ft_width_u(t_params *f, int i, int l)
{
	if (f->moins_f == 1 && f->precision == -1)
		ft_putstr_count(f->str_lst, f->scount);
	while (i < l)
	{
		if (f->zero_f == 1 && f->moins_f == 0)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
}

static	void	ft_analyze_u(t_params *f)
{
	int i;
	int l;

	i = 0;
	if (f->width <= f->precision)
	{
		l = f->precision - f->len;
		while (i++ < l)
			write_count(1, "0", 1, f->scount);
	}
	else
	{
		l = f->width - f->len;
		if (f->width != -1 && f->precision <= 0)
			ft_width_u(f, i, l);
		else if (f->width > f->precision && f->moins_f == 1)
			ft_wp_minus_u(f, i, l);
		else
			ft_wp_u(f, i, l);
	}
}

void			ft_iam_u(t_params *f, uintmax_t nb)
{
	f->str_lst = ft_itoa_base_unsint(nb, 10);
	if (ft_strcmp(f->str_lst, "0") == 0 && f->precision != -1)
	{
		free(f->str_lst);
		f->str_lst = ft_strdup("\0");
	}
	f->len = (int)ft_strlen(f->str_lst);
	ft_analyze_u(f);
	if (f->moins_f == 0 || (f->moins_f == 1 && f->width <= f->precision))
		ft_putstr_count(f->str_lst, f->scount);
	free(f->str_lst);
}
