/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unicode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 12:17:58 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 12:45:28 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_write_uni(t_params *f, unsigned char *t, int s, int *count)
{
	if (f->precision > 0 && f->precision <= f->wchar_len)
	{
		if (f->cumul_size + s <= f->precision)
		{
			write(1, t, s);
			f->cumul_size = f->cumul_size + s;
			*count = *count + s;
		}
	}
	else
	{
		write(1, t, s);
		*count = *count + s;
	}
}

void			ft_unicode_limit(wchar_t n, int size, int *count, t_params *f)
{
	unsigned int	n_bits_temp;
	unsigned char	*tab;
	unsigned int	stock_hexa;
	int				i;

	i = 1;
	if (!(tab = (unsigned char*)malloc(sizeof(*tab) * size)))
		return ;
	if (n <= 2047)
		stock_hexa = 0xC0;
	else if (n <= 65535)
		stock_hexa = 0xE0;
	else
		stock_hexa = 0xF0;
	tab[0] = n >> 6 * (size - 1) | stock_hexa;
	while (i < size)
	{
		n_bits_temp = n - ((n >> 6 * (size - i)) << 6 * (size - i));
		tab[i] = (n_bits_temp >> (6 * (size - i - 1))) | 0x80;
		i++;
	}
	ft_write_uni(f, tab, size, count);
	free(tab);
}

void			ft_check_unicode(wchar_t n, int *count, t_params *f)
{
	int		nb_octets;
	char	*tmp;

	f->scount = f->scount;
	if ((MB_CUR_MAX <= 1 && n > 255) || (n >= 0xd800 && n <= 0xdfff) || n < 0)
		*(f->scount) = -1;
	else if (MB_CUR_MAX == 1 && n > 127 && n <= 255)
		ft_putchar_count((char)n, f->scount);
	else if (n <= 127)
		ft_putchar_count(n, count);
	else if (n <= 1114111)
	{
		nb_octets = ft_count_octets(n);
		ft_unicode_limit(n, nb_octets, count, f);
	}
	else
		*(f->scount) = -1;
}

static	void	ft_check_str_norme(wchar_t *str, int *count, t_params *f, int i)
{
	if (MB_CUR_MAX == 1 && str[i] > 127 && str[i] <= 255)
	{
		if (f->cumul_size < f->precision && f->precision > 0)
			f->cumul_size = f->cumul_size + 1;
		ft_putchar_count((char)str[i], f->scount);
	}
	else if (str[i] <= 127 && f->precision > 0)
	{
		if (f->cumul_size < f->precision)
		{
			ft_putchar_count(str[i], f->scount);
			f->cumul_size = f->cumul_size + 1;
		}
	}
	else if (str[i] <= 127)
	{
		ft_putchar(str[i]);
		*count = *count + 1;
	}
	else
		ft_check_unicode((wchar_t)str[i], count, f);
}

void			ft_check_unicode_str(wchar_t *str, int *count, t_params *f)
{
	int		i;
	int		len;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	f->cumul_size = 0;
	while (str[i] != '\0' && f->precision != 0)
	{
		if (((MB_CUR_MAX <= 1 && str[i] > 255) ||
					(str[i] >= 0xd800 && str[i] <= 0xdfff) || (str[i] < 0)))
		{
			if (MB_CUR_MAX <= 1 && str[i] > 255 && f->precision > 0)
				i = i;
			else
				*(f->scount) = -1;
			return ;
		}
		else
			ft_check_str_norme(str, count, f, i);
		i++;
	}
}
