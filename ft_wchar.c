/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_string.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 13:41:29 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 23:17:13 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_wp_str(t_params *f, wchar_t *str, char *trans)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = ft_strsub(trans, 0, f->precision / (f->wchar_len / f->wchar_size));
	len = f->width - ft_strlen(tmp) * (f->wchar_len / f->wchar_size);
	if (f->moins_f == 1)
		ft_check_unicode_str(str, f->scount, f);
	while (i < len && f->precision <= f->width)
	{
		if (f->zero_f == 1)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
	if (f->moins_f != 1)
		ft_check_unicode_str(str, f->scount, f);
	free(tmp);
}

static	void	ft_prec_str(t_params *f, wchar_t *str)
{
	ft_check_unicode_str(str, f->scount, f);
}

static	void	ft_width_str(t_params *f, wchar_t *str, char *trans)
{
	int i;
	int len;

	len = ft_strlen(trans);
	i = 0;
	if (f->moins_f == 1 && f->precision == -1)
		ft_check_unicode_str(str, f->scount, f);
	if (f->precision == 0)
		len = 0;
	while (i < f->width - len)
	{
		if (f->zero_f == 1)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
	if (f->moins_f == 0 && f->precision == -1)
		ft_check_unicode_str(str, f->scount, f);
}

void			ft_wchar(t_params *f, wchar_t *str, char *trans)
{
	if (f->width != -1 && f->precision <= 0)
		ft_width_str(f, str, trans);
	else if (f->width == -1 && f->precision != -1)
		ft_prec_str(f, str);
	else if (f->width != -1 && f->precision != -1)
		ft_wp_str(f, str, trans);
	else
		ft_check_unicode_str(str, f->scount, f);
}
