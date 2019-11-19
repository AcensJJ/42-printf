/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags_printf.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 15:11:54 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 16:02:19 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

static char		*ft_do_flag4(va_list args, int *sign, t_bool *struc)
{
	char	*str;

	str = NULL;
	if (struc->arg[0] == 's')
	{
		if (!(struc->str = ft_va_null_char(args)))
		{
			*sign = -1;
			return (NULL);
		}
		if (!(str = ft_strdup(struc->str)))
			*sign = -1;
		return (str);
		free(struc->str);
		struc->str = NULL;
	}
	return (str);
}

static char		*ft_do_flag3(va_list args, int *sign, t_bool *struc)
{
	char	*str;
	char	*ptr;

	str = NULL;
	if (struc->arg[0] == 'p')
	{
		if (!(ptr = ft_uitoa_base(va_arg(args, void *), "0123456789abcdef")))
			*sign = -1;
		if (ptr != NULL)
		{
			if (!(str = ft_strjoin("0x", ptr)))
				*sign = -1;
			if (ptr != NULL)
				free(ptr);
		}
		free(struc->arg);
		struc->arg = NULL;
	}
	return (str);
}

static char		*ft_do_flag2(va_list args, int *sign, t_bool *struc)
{
	char	*str;

	str = NULL;
	if (struc->arg[0] == 'c')
	{
		if (!(str = malloc(2)))
			*sign = -1;
		else
		{
			str[0] = va_arg(args, int);
			str[1] = '\0';
		}
		free(struc->arg);
		struc->arg = NULL;
	}
	else if (struc->arg[0] == 'u')
	{
		if (!(str = ft_uitoa(va_arg(args, unsigned int))))
			*sign = -1;
		free(struc->arg);
		struc->arg = NULL;
	}
	return (str);
}

static char		*ft_do_flag(va_list args, int *sign, t_bool *struc)
{
	char	*str;

	str = NULL;
	if (struc->arg[0] == 'd' || struc->arg[0] == 'i')
	{
		if (!(str = ft_itoa(va_arg(args, int))))
			*sign = -1;
		free(struc->arg);
		struc->arg = NULL;
	}
	else if (struc->arg[0] == 'x')
	{
		if (!(str = ft_itoa_base(va_arg(args, int), "0123456789abcdef")))
			*sign = -1;
		free(struc->arg);
		struc->arg = NULL;
	}
	else if (struc->arg[0] == 'X')
	{
		if (!(str = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF")))
			*sign = -1;
		free(struc->arg);
		struc->arg = NULL;
	}
	return (str);
}

char			*ft_config_flags(va_list args, char format, int *sign,
								t_bool *struc)
{
	char	*str;

	str = NULL;
	if (!(struc->arg = ft_strdup(&format)))
	{
		*sign = -1;
		return (NULL);
	}
	if (format == 'd' || format == 'i' || format == 'x' || format == 'X')
	{
		str = ft_do_flag(args, sign, struc);
	}
	else if (format == 'c' || format == 'u')
	{
		str = ft_do_flag2(args, sign, struc);
	}
	else if (format == 'p')
	{
		str = ft_do_flag3(args, sign, struc);
	}
	else if (format == 's')
	{
		str = ft_do_flag4(args, sign, struc);
		free(struc->arg);
		struc->arg = NULL;
	}
	return (str);
}
