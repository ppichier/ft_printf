/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:18:08 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 23:13:25 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_pourcent_only(const char *str)
{
	int i;
	int len;
	int j;
	int cpt;

	j = 0;
	i = 0;
	cpt = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] != '%' && str[i] != ' ')
			j = 1;
		if (str[i] == '%')
			cpt++;
		i++;
	}
	if (j == 1)
		return (0);
	if (str[0] == '%' && cpt == 1)
		return (1);
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (ft_pourcent_only(format))
		return (count);
	va_start(ap, format);
	ft_check_format(format, ap, &count);
	va_end(ap);
	return (count);
}
