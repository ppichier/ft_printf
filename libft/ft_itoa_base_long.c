/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_long.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 17:02:54 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 18:31:29 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(long n, int base)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		(base == 10) ? i++ : i;
		n = -n;
	}
	while (n >= base)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char			*ft_itoa_base_long(long value, int base)
{
	char	*str;
	int		len;

	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	len = ft_nblen(value, base);
	if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (value < 0)
	{
		if (base == 10)
			str[0] = '-';
		value = -value;
	}
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (value % base >= 10) ? (value % base) + 55 :
			(value % base) + '0';
		value = value / base;
	}
	return (str);
}
