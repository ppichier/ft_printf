/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iam_d_i.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 17:05:31 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 23:30:01 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	long long	ft_boucle_wp_neg(t_params *f, int len, long long nb)
{
	int i;
	int j;
	int plus;

	j = 0;
	i = 0;
	plus = 0;
	(f->plus_f == 1 && nb >= 0 && f->type != 'u' && f->zero_f == 0) ?
		write_count(1, "+", 1, f->scount) : 1;
	plus = (f->plus_f == 1 && nb >= 0) ? 1 : 0;
	while (i < f->width - len - plus)
	{
		if (f->precision - i > len && f->precision > 0)
			write_count(1, "0", 1, f->scount);
		else if (f->precision - i == len && j != 1)
		{
			ft_putnbrlong_count(nb, f->scount);
			len--;
			j = 1;
		}
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
	return (nb);
}

static	long long	ft_boucle_wp(t_params *f, int len, long long nb)
{
	int i;

	i = 0;
	if (nb < 0 && f->plus_f == 1)
		len++;
	while (i < f->width - len)
	{
		if (f->width - i == f->precision + 1 && f->plus_f == 1 && nb >= 0
				&& f->type != 'u')
			write_count(1, "+", 1, f->scount);
		else if (f->width - i == f->precision + 1 && nb < 0)
		{
			write_count(1, "-", 1, f->scount);
			nb = -nb;
			len--;
		}
		else if (f->width - i > f->precision)
			write_count(1, " ", 1, f->scount);
		else
			write_count(1, "0", 1, f->scount);
		i++;
	}
	if (nb == 0 && f->precision == 0)
		write_count(1, " ", 1, f->scount);
	return (nb);
}

static	long long	ft_boucle_prec(t_params *f, int len, long long nb)
{
	int		i;
	char	*tmp;

	i = 0;
	if (nb >= 0 && f->plus_f == 1 && f->type != 'u')
		write_count(1, "+", 1, f->scount);
	if (nb < 0)
	{
		write_count(1, "-", 1, f->scount);
		len--;
		nb = -nb;
	}
	while (i < f->precision - len)
	{
		write_count(1, "0", 1, f->scount);
		i++;
	}
	if (f->precision == 0 && nb == 0)
	{
		tmp = ft_strdup("\0");
		ft_putstr_count(tmp, f->scount);
		free(tmp);
	}
	return (nb);
}

static	long long	ft_boucle_width(t_params *f, int len, long long nb)
{
	int i;

	i = 0;
	if (f->width != -1 && f->precision == -1)
	{
		if (f->space_f == 1)
			write_count(1, " ", 1, f->scount);
		if (f->space_f == 1)
			i++;
		while (i < f->width - len)
		{
			if (f->zero_f == 1 && f->moins_f == 0)
				write_count(1, "0", 1, f->scount);
			else
				write_count(1, " ", 1, f->scount);
			i++;
		}
	}
	else if (f->precision >= 0 && (f->width <= f->precision))
		return (ft_boucle_prec(f, len, nb));
	else if (f->precision >= 0 && f->width != -1 && f->moins_f == 0)
		return (ft_boucle_wp(f, len, nb));
	else if (f->precision >= 0 && f->width != -1 && f->moins_f == 1)
		return (ft_boucle_wp_neg(f, len, nb));
	return (nb);
}

void				ft_all_di(t_params *f, long long nb, int len, long long n)
{
	len = ft_count_nb(nb);
	f->precision != -1 && f->plus_f == 1 ? len-- : len;
	f->plus_f == 1 && nb >= 0 ? len++ : len;
	if (f->plus_f == 1 && nb >= 0 && (f->zero_f == 1 || f->moins_f == 1)
			&& f->precision <= 0 && f->type != 'u')
		write_count(1, "+", 1, f->scount);
	if (f->space_f == 1 && nb >= 0 && f->plus_f == 0 && len >= f->width &&
			f->type != 'u')
		write_count(1, " ", 1, f->scount);
	if ((f->zero_f == 1 || f->moins_f == 1) && nb < 0 && f->precision == -1)
	{
		write_count(1, "-", 1, f->scount);
		nb = -nb;
	}
	if (f->moins_f == 1 && f->precision <= 0)
		ft_putnbrlong_count(nb, f->scount);
	n = ft_boucle_width(f, len, nb);
	if ((f->plus_f == 1 && n >= 0 && (f->zero_f == 0 && f->moins_f == 0)
				&& f->precision == -1) && f->type != 'u')
		write_count(1, "+", 1, f->scount);
	if (f->precision == 0 && nb == 0)
		return ;
	if (f->moins_f == 0 || (f->precision >= 0 && f->width == -1)
				|| f->precision > f->width)
		ft_putnbrlong_count(n, f->scount);
}
