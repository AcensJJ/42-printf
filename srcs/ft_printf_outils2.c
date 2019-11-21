/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:42:45 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:51:33 by jacens      ###    #+. /#+    ###.fr     */
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
	}
	while ((struc->zero - (int)ft_strlen(ptr)) != i)
	{
		write(1, "0", 1);
		*valprintf += 1;
		i++;
	}
}
