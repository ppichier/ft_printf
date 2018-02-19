/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbrlong.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 19:58:10 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 12:55:37 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrunsint_count(uintmax_t n, int *count)
{
	if (n > 9)
	{
		ft_putnbrunsint_count(n / 10, count);
		ft_putnbrunsint_count(n % 10, count);
	}
	if (n <= 9)
	{
		ft_putchar(n + '0');
		*count = *count + 1;
	}
}
