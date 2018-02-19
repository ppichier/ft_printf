/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_first_check_format.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 16:06:51 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 12:14:58 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_format2(const char *format, va_list ap, int *c, int i)
{
	int		start;
	char	*stock;

	start = i;
	i = ft_check_arg_continuation(format, i);
	stock = ft_strsub(format, start, i - start + 1);
	if ((ft_fill_fields(stock, ap, c)) == 0)
	{
		free(stock);
		return (-1);
	}
	free(stock);
	return (i);
}

int		ft_check_format(const char *format, va_list ap, int *count)
{
	int			i;
	int			start;
	char		*stock;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				write_count(1, "%", 1, count);
			else
			{
				i = (ft_check_format2(format, ap, count, i));
				if (i == -1)
					return (0);
			}
		}
		else
			write_count(1, &format[i], 1, count);
		i++;
	}
	return (1);
}
