/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:42:45 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:12:00 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void		ft_print_space(int *valprintf, t_bool *struc)
{
	int i;

	i = 0;
	while (struc->space > i)
	{
		write(1, " ", 1);
		*valprintf += 1;
		i++;
	}
}

void		ft_print_zero(int *valprintf, t_bool *struc, char *ptr, char format)
{
	int		i;

	i = 0;
	if (ptr[0] == '-' && format != 's')
	{
		write(1, "-", 1);
		ptr++;
		struc->print -= 1;
		*valprintf += 1;
	}
	while ((struc->zero > i))
	{
		write(1, "0", 1);
		*valprintf += 1;
		i++;
	}
}

static void	ft_with_pre_do2(char format, int *valprintf, char *ptr,
						t_bool *struc)
{
	if (format != 's' && (ft_strcmp(ptr, "0") == 0) && struc->print == 0)
	{
		struc->space += 1;
		struc->left != 1 ? ft_print_space(valprintf, struc) : 0;
		struc->left == 1 ? ft_print_space(valprintf, struc) : 0;
	}
	else if (format != 's' && (ft_strcmp(ptr, "0") == 0))
	{
		;
	}
	else if (format != 's')
	{
		ft_print_pre(valprintf, struc, ptr, format);
	}
	else
	{
		struc->left != 1 ? ft_print_space(valprintf, struc) : 0;
		write(1, ptr, struc->print);
		*valprintf += struc->print;
		struc->left == 1 ? ft_print_space(valprintf, struc) : 0;
	}
}

void		ft_with_pre_do(char format, int *valprintf, char *ptr,
						t_bool *struc)
{
	if (format == 'p' && (ft_strcmp(ptr, "0x0") == 0) && struc->print == 0)
	{
		write(1, "0x", 2);
		*valprintf += 2;
	}
	else if (format != 's' && (ft_strcmp(ptr, "0") == 0) &&
			struc->zero == 0 && struc->space != 0 && struc->print == 0)
	{
		struc->left != 1 ? ft_print_space(valprintf, struc) : 0;
		ft_print_zero(valprintf, struc, ptr, format);
		struc->left == 1 ? ft_print_space(valprintf, struc) : 0;
	}
	else if (format != 's' && (ft_strcmp(ptr, "0") == 0) && (struc->zero != 0
		|| struc->space != 0) && struc->print != 0)
	{
		struc->left != 1 ? ft_print_space(valprintf, struc) : 0;
		ft_print_zero(valprintf, struc, ptr, format);
		write(1, "0", 1);
		struc->left == 1 ? ft_print_space(valprintf, struc) : 0;
		*valprintf += 1;
	}
	else
		ft_with_pre_do2(format, valprintf, ptr, struc);
}
