/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_icountbase.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 17:24:50 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 17:26:42 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_icountbase(int nb, int base)
{
	int count;

	count = 0;
	while (nb > 0)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}
