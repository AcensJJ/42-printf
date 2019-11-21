/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:42:45 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:23:34 by jacens      ###    #+. /#+    ###.fr     */
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
		write(1, ptr, struc->print);
		*valprintf += struc->print;
	}
}
