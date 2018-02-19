/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:12:26 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 14:12:28 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sizen(int n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	int		ft_turntopositive(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static	int		ft_isnegative(int n)
{
	int j;

	j = 0;
	if (n < 0)
		j = 1;
	return (j);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		j;

	j = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = ft_isnegative(n);
	n = ft_turntopositive(n);
	len = ft_sizen(n);
	if (j)
		len = len + 1;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len - 1] = n + '0';
	if (j)
		str[len] = '-';
	return (str);
}
