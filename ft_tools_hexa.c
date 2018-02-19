/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools_hexa.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 13:35:35 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 13:58:29 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_diese_hexa(t_params *f)
{
	if ((f->str_lst)[0] != '\0' && ft_strcmp(f->str_lst, "0") != 0)
	{
		if (f->diese_f && f->type == 'x')
			write_count(1, "0x", 2, f->scount);
		else if (f->diese_f && f->type == 'X')
			write_count(1, "0X", 2, f->scount);
		else if (f->diese_f && (f->type == 'o' || f->type == 'O'))
			write_count(1, "0", 1, f->scount);
	}
	if (f->type == 'p')
		write_count(1, "0x", 2, f->scount);
}

int		ft_count_nb(long long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		ft_minus_hexa(t_params *f, int k)
{
	if (f->moins_f == 1 && f->precision == -1)
		ft_putstr_count(f->str_lst, f->scount);
	if (f->diese_f == 1 && f->precision == -1 && (ft_strcmp(f->str_lst, "0")
				== 0 || ft_strcmp(f->str_lst, "\0") == 0))
		k = 2;
	else if ((f->diese_f == 1 || f->type == 'p'))
		k = (f->type == 'o' || f->type == 'O') ? 1 : 2;
	return (k);
}

int		ft_v(t_params *f)
{
	if (f->precision >= f->len)
		return (f->precision);
	else
		return (f->len);
}

int		ft_apply_diese_hexa(t_params *f, int j, int *i)
{
	ft_diese_hexa(f);
	i = (f->type == 'o' || f->type == 'O') ? i + 1 : i + 2;
	j = 1;
	return (j);
}
