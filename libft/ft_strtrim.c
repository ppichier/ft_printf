/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 15:05:36 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 15:05:38 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && s[i] != '\0')
		len--;
	str = ft_strsub(s, i, (len - i + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}
