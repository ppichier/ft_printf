/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbrlong.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 19:58:10 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 12:43:33 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrunsint(uintmax_t n)
{
	if (n > 9)
	{
		ft_putnbrunsint(n / 10);
		ft_putnbrunsint(n % 10);
	}
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
}
