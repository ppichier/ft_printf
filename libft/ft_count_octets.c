/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_octets.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 16:13:18 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 12:35:34 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_octets(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base_unsint(n, 2);
	while (str[i] != '\0')
		i++;
	free(str);
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else
		return (4);
}
