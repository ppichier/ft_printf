/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:56:39 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 14:56:41 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	lens1;
	size_t	i;

	i = 0;
	lens1 = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[lens1] = s2[i];
		lens1++;
		i++;
	}
	s1[lens1] = '\0';
	return (s1);
}
