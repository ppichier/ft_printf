/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_len_wchar.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 16:10:40 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 15:52:54 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_wchar(wchar_t *str)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 255)
			cpt = cpt + 1;
		else
			cpt = cpt + ft_count_octets(str[i]);
		i++;
	}
	return (cpt);
}
