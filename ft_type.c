/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 16:06:59 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 21:31:11 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sf_isstring(t_params *f, char *str)
{
	if (f->type == 's' && f->l_s)
		ft_sf_iswchar_str(f, (wchar_t*)str);
	else if (f->type == 's')
	{
		if (str == NULL)
		{
			str = ft_strdup("(null)");
			free(str);
		}
		ft_string(f, str);
	}
}

void	ft_sf_isint(t_params *f, long long nb)
{
	if (f->z_s == 0 && f->j_s == 0)
	{
		if (f->l_s == 0 && f->ll_s == 0)
		{
			if (f->h_s == 1 && f->type != 'D')
				nb = ft_itosh(nb);
			else if (f->hh_s == 1 && f->type != 'D')
				nb = ft_itoshsh(nb);
		}
	}
	if (f->type == 'd' || f->type == 'i' || f->type == 'D')
		ft_iam_d_i(f, nb);
	else if (f->type == 'c' && f->l_s)
		ft_sf_iswchar(f, (wchar_t)nb);
	else if (f->type == 'c')
		ft_char(f, nb);
}

void	ft_sf_iswchar(t_params *f, wchar_t nb)
{
	ft_wcsolo(f, nb);
}

void	ft_sf_isunsint(t_params *f, uintmax_t nb)
{
	if (f->z_s == 0 && f->j_s == 0)
	{
		if (f->l_s == 0 && f->ll_s == 0)
		{
			if (f->h_s == 1 && f->type != 'U' && f->type != 'O')
				nb = ft_uitosh(nb);
			else if (f->hh_s == 1 && f->type != 'U' && f->type != 'O')
				nb = ft_uitoshsh(nb);
		}
	}
	if (f->type == 'u' || f->type == 'U')
		ft_iam_u(f, nb);
	else if (f->type == 'x' || f->type == 'X' || f->type == 'o'
			|| f->type == 'O')
		ft_hexa(f, nb);
}

void	ft_sf_isvoid(t_params *f, void *p)
{
	char *tmp;
	char *tmp2;

	if (f->type == 'p')
	{
		tmp = ft_itoa_base_unsint((uintmax_t)p, 16);
		tmp2 = ft_strtolower(tmp);
		f->str_lst = ft_strdup(tmp2);
		free(tmp);
		free(tmp2);
		ft_hexa(f, (uintmax_t)p);
	}
}
