/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_char.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:53:14 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 22:46:14 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_width_char(t_params *f, int nb)
{
	int i;

	i = 1;
	if (f->moins_f == 1)
		ft_putchar_count(nb, f->scount);
	while (i < f->width)
	{
		if (f->zero_f == 1)
		{
			if (f->type == '%' && f->moins_f == 1)
				write_count(1, " ", 1, f->scount);
			else
				write_count(1, "0", 1, f->scount);
		}
		else
			write_count(1, " ", 1, f->scount);
		i++;
	}
	if (f->moins_f != 1)
		ft_putchar_count(nb, f->scount);
}

void			ft_char(t_params *f, int nb)
{
	if (f->width != -1)
		ft_width_char(f, nb);
	else
		ft_putchar_count(nb, f->scount);
}
