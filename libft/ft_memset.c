/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:44:49 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 14:44:52 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	size_t			i;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	str = (char*)b;
	while (i < len)
	{
		str[i] = a;
		i++;
	}
	return (b);
}
