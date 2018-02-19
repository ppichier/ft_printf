/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_char.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:53:14 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 23:16:20 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_width_char(t_params *f, wchar_t nb, int len)
{
	int i;

	i = 0;
	if (f->moins_f == 1)
		ft_check_unicode(nb, f->scount, f);
	while (i < f->width - len)
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
		ft_check_unicode(nb, f->scount, f);
}

void			ft_wcsolo(t_params *f, wchar_t nb)
{
	int	len;

	len = ft_count_octets(nb);
	if (f->width != -1)
		ft_width_char(f, nb, len);
	else
		ft_check_unicode(nb, f->scount, f);
}
