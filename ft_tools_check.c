/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools_check.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 09:36:16 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 21:32:42 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_valid_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int		ft_is_flags(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')
		return (1);
	return (0);
}

int		ft_check_after_is_type_exist(const char *format, int i)
{
	while (format[i] != '\0')
	{
		if (ft_is_valid_type(format[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_size(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		ft_check_arg_continuation(const char *format, int i)
{
	while (format[i] != '\0')
	{
		while (ft_is_size(format[i]))
			i++;
		while (ft_is_flags(format[i]))
			i++;
		while (ft_isdigit(format[i]))
			i++;
		while (format[i] == '.')
			i++;
		while (ft_isdigit(format[i]))
			i++;
		while (ft_is_size(format[i]))
			i++;
		if (ft_is_valid_type(format[i]))
			return (i);
		if (!(ft_is_size(format[i])) && !(ft_is_flags(format[i])) &&
				!(ft_isdigit(format[i])) && !(format[i] == '.'))
			return (i);
	}
	return (i);
}
