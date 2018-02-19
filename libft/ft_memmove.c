/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:44:08 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 14:44:12 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*s;

	dest = dst;
	s = src;
	if (src >= dst)
	{
		ft_memcpy(dest, s, len);
	}
	else
	{
		s = s + len;
		dest = dest + len;
		while (len--)
		{
			dest--;
			s--;
			*dest = *s;
		}
	}
	return (dst);
}
