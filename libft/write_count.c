/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_count.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 17:45:54 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 12:30:30 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	write_count(int sortie, const char *s, int size, int *count)
{
	write(sortie, s, size);
	*count = *count + size;
}
