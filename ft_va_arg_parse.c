/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_va_arg_parse.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 19:18:12 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 21:30:26 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sf_iswchar_str(t_params *f, wchar_t *str)
{
	return (ft_analyze_wchar(str, f->scount, f));
}

int		ft_va_arg_parse_wcharstr(t_params *f, va_list ap)
{
	return (ft_sf_iswchar_str(f, va_arg(ap, wchar_t *)));
}

void	ft_va_arg_parse_char(t_params *f, va_list ap)
{
	if (f->type == 's')
		ft_sf_isstring(f, va_arg(ap, char *));
	else if (f->type == 'C')
		ft_sf_iswchar(f, va_arg(ap, wchar_t));
	else if (f->type == 'p')
		ft_sf_isvoid(f, va_arg(ap, void*));
	else if (f->type != '\0')
	{
		if (f->width > 0)
			ft_char(f, f->type);
		else
			ft_putchar_count(f->type, f->scount);
	}
}

void	ft_va_arg_parse_int1(t_params *f, va_list ap)
{
	if (f->type == 'c')
		ft_sf_isint(f, va_arg(ap, int));
	else if (f->z_s)
		ft_sf_isint(f, va_arg(ap, size_t));
	else if (f->j_s)
		ft_sf_isint(f, va_arg(ap, intmax_t));
	else if (f->l_s)
		ft_sf_isint(f, va_arg(ap, long int));
	else if (f->ll_s)
		ft_sf_isint(f, va_arg(ap, intmax_t));
	else if (f->hh_s)
		ft_sf_isint(f, va_arg(ap, long long));
	else if (f->h_s)
		ft_sf_isint(f, va_arg(ap, long long));
	else
		ft_sf_isint(f, va_arg(ap, int));
}

void	ft_va_arg_parse_int2(t_params *f, va_list ap)
{
	if (f->type == 'o' || f->type == 'u' || f->type == 'x' ||
			f->type == 'X')
	{
		if (f->z_s)
			ft_sf_isunsint(f, va_arg(ap, size_t));
		else if (f->j_s)
			ft_sf_isunsint(f, va_arg(ap, uintmax_t));
		else if (f->ll_s)
			ft_sf_isunsint(f, va_arg(ap, uintmax_t));
		else if (f->l_s)
			ft_sf_isunsint(f, va_arg(ap, unsigned long int));
		else if (f->hh_s)
			ft_sf_isunsint(f, va_arg(ap, unsigned long int));
		else if (f->h_s)
			ft_sf_isunsint(f, va_arg(ap, unsigned long int));
		else
			ft_sf_isunsint(f, va_arg(ap, unsigned int));
	}
	else if (f->type == 'O' || f->type == 'U')
		ft_sf_isunsint(f, va_arg(ap, unsigned long int));
	else if (f->type == 'D')
		ft_sf_isint(f, va_arg(ap, long int));
}
