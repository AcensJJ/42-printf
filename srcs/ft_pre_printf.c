/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pre_printf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 16:59:43 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 13:31:37 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

int			ft_no_pre(const char *format, va_list args, int *sign,
					t_bool *struc)
{
	char	*ptr;

	ptr = ft_config_flags(args, format[0], sign, struc);
	if (ptr != NULL)
	{
		write(1, ptr, ft_strlen(ptr));
		free(ptr);
	}
	else
		return (-1);
	return (1);
}
