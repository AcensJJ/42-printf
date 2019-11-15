/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags_printf.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 15:11:54 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 17:03:11 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/include/get_next_line.h"
#include "./libft/include/libft.h"

static char		*ft_do_flag2(va_list args, char format, int *sign)
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	if (format == 'c')
	{
		if (!(str = malloc(2)))
			sign = -1;
		else
		{
			str[0] = va_arg(args, int);
			str[1] = 0;
		}
	}
	else if (format == 'u')
		if ((str = ft_itoa(va_arg(args, unsigned int)) == NULL))
			sign = -1;
	else if (format == 'p')
		;
	return (str);
}

char		*ft_do_flag(va_list args, char format, int *sign)
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	if (format == 'd' || format == 'i')
		if ((str = ft_itoa(va_arg(args, int)) == NULL))
			sign = -1;
	else if (format == 'x')
		if ((str = ft_itoa_base(va_arg(args, int), '0123456789abcdef')))
			sign = -1;
	else if (format == 'X')
		if ((str = ft_itoa_base(va_arg(args, int), '0123456789ABCDEF')))
			sign = -1;
	else if (format == 's')
		if ((str = ft_strdup(va_arg(args, char *))))
			sign = -1;
	else
		str = ft_do_flag2(args, format, &sign);
	return (str);
}
