/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pre_printf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 16:59:43 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:21:28 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

static void	ft_with_dot(const char *format, va_list args, t_bool *struc)
{
	int i;

	i = 0;
	if (format[i] == '-')
	{
		struc->left = 1;
		i++;
	}
	if (format[i] >= '0' && format[i] <= '9')
		struc->print = ft_atoi(&format[i]);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '*')
	{
		struc->print = va_arg(args, int);
		i++;
	}
	i++;
	if (format[i] >= '0' && format[i] <= '9')
		struc->zero = ft_atoi(&format[i]);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '*')
		struc->zero = va_arg(args, int);
}

static void	ft_no_dot(const char *format, va_list args, t_bool *struc)
{
	int i;

	i = 0;
	if (format[i] == '-')
	{
		struc->left = 1;
		i++;
	}
	if (format[i] >= '1' && format[i] <= '9')
	{
		struc->print = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else if (format[i] == '0')
	{
		struc->zero = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else if (format[i] == '*')
		struc->print = va_arg(args, int);
}

static int	ft_check_dot(const char *format, va_list args, t_bool *struc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((format[i] >= '0' && format[i] <= '9') ||
	(format[i] == '.' || format[i] == '*' || format[i] == '-'))
	{
		if (format[i] == '.')
			j++;
		i++;
	}
	if (j > 0)
		ft_with_dot(format, args, struc);
	else
		ft_no_dot(format, args, struc);
	j > 0 && struc->print == -1 ? struc->print = 0 : 0;
	return (i);
}

int			ft_with_pre(const char *format, va_list args, int *valprintf,
						t_bool *struc)
{
	char	*ptr;
	int		i;

	i = ft_check_dot(format, args, struc);
	ptr = ft_config_flags(args, format[i], valprintf, struc);
	if (ptr == NULL)
		return (-1);
	format[i] == 's' && struc->print == -1 && struc->zero != -1 ?
	struc->print = struc->zero : 0;
	format[i] != 's' ? struc->space = struc->print : 0;
	format[i] != 's' ? struc->print = (int)ft_strlen(ptr) : 0;
	struc->print == -1 ? struc->print = (int)ft_strlen(ptr) : 0;
	struc->zero == -1 ? struc->zero = struc->print : 0;
	struc->space < struc->zero ? struc->space = struc->zero : 0;
	ft_with_pre_do(format[i], valprintf, ptr, struc);
	free(ptr);
	return (++i);
}

int			ft_no_pre(const char *format, va_list args, int *valprintf,
					t_bool *struc)
{
	char	*ptr;
	int		i;
	char	c;

	c = 0;
	ptr = ft_config_flags(args, format[0], valprintf, struc);
	if (ptr != NULL || format[0] == 'c')
	{
		i = 1;
		if (format[0] == 'c' && ptr[0] == 0)
			write(1, &c, 1);
		else
		{
			i = ft_strlen(ptr);
			write(1, ptr, i);
		}
		*valprintf += i;
		free(ptr);
		return (1);
	}
	return (-1);
}
