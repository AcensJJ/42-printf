/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 14:08:20 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 15:31:33 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

static int		ft_verif_flag(char *flag, char verif)
{
	int i;

	i = -1;
	while (flag[++i])
		if (flag[i] == verif)
			return (1);
	return (0);
}

static int		ft_check_flags(const char *format, va_list args, char *flag)
{
	int		i;
	int		sign;
	t_bool	*struc;

	struc = NULL;
	if (!(struc = ft_set_struct(struc)))
		return (-1);
	i = 1;
	sign = 0;
	if (format[i] == '%')
	{
		write(1, &format[i], 1);
		i += 1;
	}
	else if (format[i] >= '0' && format[i] <= '9')
		i += 0;
	else if (format[i] == '.' || format[i] == '*' || format[i] == '-')
		i += 0;
	else if (ft_verif_flag(flag, format[i]) == 1)
		i += ft_no_pre(&format[i], args, &sign, struc);
	ft_end_one_check(struc);
	if (sign == -1)
		return (-1);
	return (i);
}

static int		ft_write(const char *format)
{
	int i;

	i = ft_strlchr(format, '%');
	write(1, format, i);
	return (i);
}

static int		ft_init(const char *format, va_list args, char *flag)
{
	int		i;
	int		j;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = ft_check_flags(&format[i], args, flag);
			if (j == -1)
				return (-1);
			i += j;
		}
		i += ft_write(&format[i]);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	*flag;

	if ((flag = ft_strdup("cspdiuxX")) == NULL)
		return (-1);
	va_start(args, format);
	i = ft_init(format, args, flag);
	va_end(args);
	free(flag);
	return (0);
}
