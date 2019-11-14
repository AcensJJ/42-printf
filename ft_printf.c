/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 14:08:20 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 18:20:00 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(const char *format, va_list args)
{
	int i;

	i = 1;
	return (i);
}

int		ft_write(const char *format)
{
	int i;

	i = ft_strlchr(format, '%');
	write(1, format, i);
	return (i);
}

int		ft_init(const char *format, va_list args)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		format[i] == '%' ? i = ft_check_flags(format, args) :
		i += ft_write(&format[i]);
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = ft_init(format, args);
	va_end(args);
	return (0);
}
