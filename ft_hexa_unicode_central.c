/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hexa_central.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 22:27:50 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 13:08:39 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_wchar_isnot_valid(wchar_t *str, t_params *f)
{
	int t[3];
	int	tmp_count;

	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	tmp_count = *(f->scount);
	while (str[t[0]++] != '\0')
	{
		t[2] = t[2] + ft_count_octets(str[t[0]]);
		if (((MB_CUR_MAX <= 1 && str[t[0]] > 255) ||
			(str[t[0]] >= 0xd800 && str[t[0]] <= 0xdfff) || (str[t[0]] < 0)))
		{
			*(f->scount) = -1;
			t[1] = 1;
			break ;
		}
	}
	if (f->precision > 0 && f->precision < t[2])
	{
		*(f->scount) = tmp_count;
		t[1] = 0;
	}
	return (t[1]);
}

int		ft_analyze_wchar(wchar_t *str, int *count, t_params *f)
{
	char	*trans;
	int		len;
	int		size;
	int		i;

	if (str == NULL)
	{
		ft_putstr_count("(null)", count);
		return (0);
	}
	if (ft_check_wchar_isnot_valid(str, f))
		return (-1);
	len = ft_len_wchar(str);
	i = 0;
	while (str[i] != '\0')
		i++;
	f->wchar_size = i;
	f->wchar_len = len;
	trans = ft_strnew_a_size(len);
	ft_wchar(f, str, trans);
	free(trans);
	return (1);
}

void	ft_analyze_hexa(t_params *f)
{
	int i;
	int l;
	int j;

	i = 0;
	j = 0;
	if (f->width <= f->precision)
	{
		l = f->precision - f->len;
		ft_diese_hexa(f);
		if (ft_strcmp(f->str_lst, "0") != 0 && ft_strcmp(f->str_lst, "\0") != 0)
			(f->type == 'o' || f->type == 'O') && f->diese_f == 1 ? i++ : i;
		while (i++ < l)
			write_count(1, "0", 1, f->scount);
	}
	else
	{
		l = f->width - f->len;
		if (f->width != -1 && f->precision <= 0)
			ft_width_hexa(f, i, l, j);
		else if (f->width > f->precision && f->moins_f == 1)
			ft_wp_minus(f, i, l, j);
		else
			ft_wp_hexa(f, i, l, j);
	}
}

void	ft_hexa(t_params *f, uintmax_t nb)
{
	char	*tmp;
	int		base;

	base = (f->type == 'o' || f->type == 'O') ? 8 : 16;
	if (f->type == 'x')
	{
		tmp = ft_itoa_base_unsint(nb, 16);
		f->str_lst = ft_strtolower(tmp);
		free(tmp);
	}
	else if (f->type != 'p')
		f->str_lst = ft_itoa_base_unsint(nb, base);
	if (ft_strcmp(f->str_lst, "0") == 0 && f->precision != -1)
		f->str_lst = ft_strdup("\0");
	f->len = (int)ft_strlen(f->str_lst);
	if (nb == 0 && (f->type == 'o' || f->type == 'O') &&
			f->diese_f == 1 && f->precision == 0)
		write_count(1, "0", 1, f->scount);
	else
		ft_analyze_hexa(f);
	if (f->moins_f == 0 || (f->moins_f == 1 && f->width <= f->precision))
		ft_putstr_count(f->str_lst, f->scount);
	free(f->str_lst);
}
