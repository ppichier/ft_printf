/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_init.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 21:08:36 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 12:45:07 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_iam_d_i(t_params *f, long long nb)
{
	int				len;
	long long		n;

	len = 0;
	if (f->precision < 0)
		ft_all_di(f, nb, len, n);
	else if (f->precision != -1 && f->width <= 0)
		ft_all_di(f, nb, len, n);
	else if (f->precision != -1 && f->width > 0)
		ft_all_di(f, nb, len, n);
	else
		ft_putnbrlong_count(nb, f->scount);
}

static void		ft_fill_flags(t_params *f)
{
	int i;

	i = 0;
	while ((f->flags)[i] != '\0')
	{
		f->flags[i] == '#' ? f->diese_f = 1 : i;
		f->flags[i] == '0' ? f->zero_f = 1 : i;
		f->flags[i] == '-' ? f->moins_f = 1 : i;
		f->flags[i] == '+' ? f->plus_f = 1 : i;
		f->flags[i] == ' ' ? f->space_f = 1 : i;
		i++;
	}
}

static	void	ft_initialize_fields(t_params *f)
{
	f->type = '\0';
	f->hh_s = 0;
	f->h_s = 0;
	f->ll_s = 0;
	f->l_s = 0;
	f->j_s = 0;
	f->z_s = 0;
	f->width = 0;
	f->precision = -1;
	f->diese_f = 0;
	f->zero_f = 0;
	f->moins_f = 0;
	f->plus_f = 0;
	f->space_f = 0;
}

int				ft_repartition_after_parse(t_params *f, va_list ap)
{
	if (f->type == 'd' || f->type == 'c' || f->type == 'i')
		ft_va_arg_parse_int1(f, ap);
	else if (f->type == 'o' || f->type == 'u' || f->type == 'X' ||
			f->type == 'x' || f->type == 'D' || f->type == 'O' ||
			f->type == 'U')
		ft_va_arg_parse_int2(f, ap);
	else if (f->type == 'S' || (f->type == 's' && f->l_s == 1))
	{
		if (ft_va_arg_parse_wcharstr(f, ap) == -1)
		{
			free(f->flags);
			free(f->size);
			free(f->size2);
			free(f);
			return (0);
		}
	}
	else if (f->type != '\0')
		ft_va_arg_parse_char(f, ap);
	else
		return (0);
	return (1);
}

int				ft_fill_fields(char *stock, va_list ap, int *count)
{
	t_params	*f;
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(stock);
	f = (t_params*)malloc(sizeof(t_params));
	f->scount = count;
	ft_initialize_fields(f);
	while (i < len)
	{
		i = ft_parse_stock_f_w(stock, f, i);
		ft_fill_flags(f);
		ft_fill_size_operator(f, f->size);
		ft_fill_size_operator(f, f->size2);
	}
	if (ft_repartition_after_parse(f, ap) == 0)
		return (0);
	free(f->flags);
	free(f->size);
	free(f->size2);
	free(f);
	return (1);
}
