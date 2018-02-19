/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conv_intoctal.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:09:49 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 15:13:28 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_conv_intoctal(int nb)
{
	char	*str;
	char	*rev;
	int		count;
	int		i;

	i = 0;
	if (nb < 8)
	{
		ft_putnbr(nb);
		return (NULL);
	}
	count = ft_icountbase(nb, 8);
	if (!(str = (char*)malloc(sizeof(*str) * count + 1)))
		return (NULL);
	str[count] = '\0';
	while (nb > 0)
	{
		str[i] = (nb % 8) + '0';
		nb = nb / 8;
		i++;
	}
	rev = ft_strrev(str);
	return (rev);
}
