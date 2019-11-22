/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:42:45 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 12:41:29 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void	ft_print_zero(int *valprintf, t_bool *struc, char *ptr)
{
	int		i;

	i = 0;
	if (ptr[0] == '-')
	{
		write(1, "-", 1);
		ptr++;
		struc->print -= 1;
		*valprintf += 1;
		struc->space -= 1;
	}
	while ((struc->zero - (int)ft_strlen(ptr)) != i)
	{
		write(1, "0", 1);
		*valprintf += 1;
		i++;
	}
}

void	ft_with_pre_do(char format, int *valprintf, char *ptr,
						t_bool *struc)
{
	format == 's' ? struc->zero = 0 : 0;
	format == 's' && struc->print == 0 && struc->space > 0 ?
	struc->print = struc->space : 0;
	if (format == 'p' && (ft_strcmp(ptr, "0x0") == 0))
	{
		write(1, "0x", 2);
		*valprintf += 2;
	}
	else if (format != 's' && (ft_strcmp(ptr, "0") == 0))
	{
		;
	}
	else if (format != 's')
		ft_print_pre(valprintf, struc, ptr, format);
	else
	{
		format == 's' && struc->print > (int)ft_strlen(ptr) ?
		struc->space -= (int)ft_strlen(ptr) : 0;
		format == 's' && struc->print > (int)ft_strlen(ptr) ?
		struc->print = (int)ft_strlen(ptr) : 0;
		if (struc->print < struc->space)
			ft_print_space(valprintf, struc);
		write(1, ptr, struc->print);
		*valprintf += struc->print;
	}
}
