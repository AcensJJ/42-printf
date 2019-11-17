/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags_printf.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 15:11:54 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 17:51:15 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/include/get_next_line.h"
#include "./libft/include/libft.h"

static char		*ft_do_flag3(va_list args, char format, int *sign,
							t_bool *struc)
{
	char	*str;
	char	*ptr;

	if (format == 'p')
	{
		if ((ptr = ft_uitoa_base(va_arg(args, void *),
			"0123456789abcdef")) == NULL)
			*sign = -1;
		else if (((str = malloc(ft_strlen(ptr))) == NULL))
			*sign = -1;
		if (*sign != -1)
		{
			str = ft_strcat(ft_strdup("0x"), ptr);
			if ((struc->arg = ft_strdup("p")) == NULL)
				*sign = -1;
		}
	}
	else if (format == 's')
	{
		if ((str = ft_strdup(va_arg(args, char *))) ||
		(struc->arg = ft_strdup("s")) == NULL)
			*sign = -1;
	}
	return (str);
}

static char		*ft_do_flag2(va_list args, char format, int *sign,
							t_bool *struc)
{
	char	*str;

	str = NULL;
	if (format == 'c')
	{
		if (!(str = malloc(2)))
			*sign = -1;
		else
		{
			str[0] = va_arg(args, int);
			str[1] = 0;
		}
		if ((struc->arg = ft_strdup("c")) == NULL)
			*sign = -1;
	}
	else if (format == 'u')
	{
		if (((str = ft_itoa(va_arg(args, unsigned int))) == NULL)
		|| (struc->arg = ft_strdup("u")) == NULL)
			*sign = -1;
	}
	else
		str = ft_do_flag2(args, format, sign, struc);
	return (str);
}

char			*ft_do_flag(va_list args, char format, int *sign, t_bool *struc)
{
	char	*str;

	str = NULL;
	if (format == 'd' || format == 'i')
	{
		if (((str = ft_itoa(va_arg(args, int))) == NULL)
		|| (struc->arg = ft_strdup("d")) == NULL)
			*sign = -1;
	}
	else if (format == 'x')
	{
		if (((str = ft_itoa_base(va_arg(args, int), "0123456789abcdef")) == NULL)
		|| (struc->arg = ft_strdup("x")) == NULL)
			*sign = -1;
	}
	else if (format == 'X')
	{
		if (((str = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF")) == NULL)
		|| (struc->arg = ft_strdup("X")) == NULL)
			*sign = -1;
	}
	else
		str = ft_do_flag2(args, format, sign, struc);
	return (str);
}
