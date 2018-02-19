/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:59:15 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 14:59:18 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *s, char c)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	if (s == NULL)
		return (0);
	if (s[0] != c && s[0] != '\0')
		nb++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			nb++;
		i++;
	}
	return (nb);
}

static char	*ft_nbletters(char const *s, int i, char c)
{
	char	*tab;

	if (s == NULL)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(tab = (char*)malloc(sizeof(*tab) * (i + 1))))
		return (NULL);
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		ptr;

	i = 0;
	ptr = 0;
	if (s == NULL)
		return (NULL);
	if (!(dest = (char**)malloc(sizeof(*dest) * (ft_nbwords(s, c) + 1))))
		return (NULL);
	while (i < ft_nbwords(s, c))
	{
		j = 0;
		while (s[ptr] == c && s[ptr] != '\0')
			ptr++;
		if ((dest[i] = ft_nbletters(s, ptr, c)) == NULL)
			return (NULL);
		while (s[ptr] != c && s[ptr] != '\0')
			dest[i][j++] = s[ptr++];
		dest[i++][j] = '\0';
	}
	dest[i] = 0;
	return (dest);
}
