/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pre_printf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 16:59:43 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 18:15:49 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/include/get_next_line.h"
#include "./libft/include/libft.h"

t_bool		*ft_set_struct(t_bool *struc)
{
	if (struc == NULL)
		if (!(struc = malloc(sizeof(struc))))
			return (NULL);
	struc->arg = malloc(2);
	struc->pre = 0;
	struc->zero = 0;
	struc->pre_star = 0;
	struc->arg = NULL;
	return (struc);
}

int			ft_no_pre(const char *format, va_list args, int *sign,
					t_bool *struc)
{
	char	*ptr;

	ptr = ft_do_flag(args, format[0], sign, struc);
	if (*sign == -1)
		return (-1);
	write(1, ptr, ft_strlen(ptr));
	free(ptr);
	return (1);
}
