/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 17:10:14 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 17:12:33 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(dst = (char*)malloc(sizeof(*dst) * len + 1)))
		return (NULL);
	dst[len] = '\0';
	len--;
	while (len >= 0)
	{
		dst[i] = str[len];
		i++;
		len--;
	}
	return (dst);
}
