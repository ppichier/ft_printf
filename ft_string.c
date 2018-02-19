/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_string.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 13:41:29 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 19:32:52 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_wp_str(t_params *f, char *str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = ft_strsub(str, 0, f->precision);
	len = ft_strlen(tmp);
	if (f->moins_f == 1)
		ft_putstr_count(tmp, f->scount);
	while (i < f->width - len)
	{
		if (f->zero_f == 1)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
	if (f->moins_f != 1)
		ft_putstr_count(tmp, f->scount);
	free(tmp);
}

static	void	ft_prec_str(t_params *f, char *str)
{
	char *tmp;

	tmp = ft_strsub(str, 0, f->precision);
	ft_putstr_count(tmp, f->scount);
	free(tmp);
}

static	void	ft_width_str(t_params *f, char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	if (f->moins_f == 1)
		ft_putstr_count(str, f->scount);
	while (i < f->width - len)
	{
		if (f->zero_f == 1 && f->moins_f == 1)
			write_count(1, " ", 1, f->scount);
		else if (f->zero_f == 1)
			write_count(1, "0", 1, f->scount);
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
	if (f->moins_f != 1)
		ft_putstr_count(str, f->scount);
}

void			ft_string(t_params *f, char *str)
{
	if (f->width != -1 && f->precision == -1)
		ft_width_str(f, str);
	else if (f->width == -1 && f->precision != -1)
		ft_prec_str(f, str);
	else if (f->width != -1 && f->precision != -1)
		ft_wp_str(f, str);
	else
		ft_putstr_count(str, f->scount);
}
