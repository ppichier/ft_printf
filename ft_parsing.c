/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 19:15:02 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 21:26:00 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_size_operator(t_params *f, char *str_size)
{
	int i;

	i = 0;
	while ((str_size)[i] != '\0')
	{
		if (str_size[i] == 'h' && str_size[i + 1] == 'h')
		{
			f->hh_s = 1;
			i++;
		}
		else if (str_size[i] == 'h')
			f->h_s = 1;
		else if (str_size[i] == 'l' && str_size[i + 1] == 'l')
		{
			f->ll_s = 1;
			i++;
		}
		else if (str_size[i] == 'l')
			f->l_s = 1;
		else if (str_size[i] == 'j')
			f->j_s = 1;
		else if (str_size[i] == 'z')
			f->z_s = 1;
		i++;
	}
}

int		ft_parse_stock_p_s_t(t_params *fields, char *stock, int i)
{
	int		start;
	char	*tmp;

	start = i;
	while (ft_is_size(stock[i]) && stock[i])
		i++;
	tmp = ft_strsub(stock, start, i - start);
	fields->size = ft_strdup(tmp);
	free(tmp);
	if (ft_is_valid_type(stock[i]) || !(ft_is_size(stock[i]) &&
			ft_isdigit(stock[i]) && ft_is_flags(stock[i]) && stock[i] == '.'))
	{
		fields->type = stock[i];
		fields->valid = (ft_is_valid_type(stock[i]));
		return (i + 1);
	}
	return (i);
}

int		ft_parse_stock_p_s_t_1(t_params *fields, char *stock, int i)
{
	int		start;
	char	*tmp;

	while (stock[i] == '+')
	{
		fields->plus_f = 1;
		i++;
	}
	while (stock[i] == '.')
		i++;
	start = i;
	while (ft_isdigit(stock[i]) && stock[i])
		i++;
	tmp = ft_strsub(stock, start, i - start);
	if (fields->precision > 0 && stock[i - 1] == '.' && !(ft_isdigit(stock[i])))
		fields->precision = 0;
	else if (stock[i - 1] == '.' && !(ft_isdigit(stock[i])))
		fields->precision = 0;
	else if (tmp[0] != '\0')
		fields->precision = ft_atoi(tmp);
	free(tmp);
	i = ft_parse_stock_p_s_t(fields, stock, i);
	return (i);
}

int		ft_parse_stock_f_w(char *stock, t_params *fields, int i)
{
	int		start;
	char	*tmp;

	while (ft_is_size(stock[i]) && stock[i])
		i++;
	tmp = ft_strsub(stock, 0, i);
	fields->size2 = ft_strdup(tmp);
	free(tmp);
	start = i;
	while (ft_is_flags(stock[i]) && stock[i])
		i++;
	tmp = ft_strsub(stock, start, i - start);
	fields->flags = ft_strdup(tmp);
	free(tmp);
	start = i;
	while (ft_isdigit(stock[i]) && stock[i])
		i++;
	tmp = ft_strsub(stock, start, i - start);
	if ((fields->width == 0 || fields->width == -1) && tmp[0] != '\0')
		fields->width = ft_atoi(tmp);
	else if (tmp[0] == '\0' && (fields->width == 0 || fields->width == -1))
		fields->width = -1;
	free(tmp);
	i = ft_parse_stock_p_s_t_1(fields, stock, i);
	return (i);
}
