/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 14:08:20 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 16:42:47 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/include/get_next_line.h"
#include "./libft/include/libft.h"

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
	char	*print;

	i = 1;
	sign = 0;
	if (format[i] >= '0' && format[i] <= '9')
		;
	else if (format[i] == '.' || format[i] == '*' || format[i] == '-')
		;
	else if (ft_verif_flag(flag, format[i]) == 1)
	{
		i += 1;
		print = ft_do_flag(args, format[i], &sign);
		if (sign == -1)
			return (-1);
		write(1, print, ft_strlen(print));
		free(print);
	}
	return (i);
}

static int		ft_write(const char *format)
{
	int i;

	i = ft_strlchr(format, ' ');
	write(1, format, i);
	return (i);
}

static int		ft_init(const char *format, va_list args, t_list *flags)
{
	int		i;
	int		j;
	char	*flag;

	if (!(flag = malloc(ft_strlen('cspdiuxX') + 1)))
		return (NULL);
	flag = 'cspdiuxX\0';
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
		while (format[i] == ' ')
		{
			write(1, format, 1);
			i++;
		}
	}
	free(flag);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	*flags;
	int		i;

	va_start(args, format);
	i = ft_init(format, args, flags);
	va_end(args);
	return (0);
}
