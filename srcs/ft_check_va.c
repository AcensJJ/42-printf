/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_va.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 10:12:40 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 14:38:29 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

char	*ft_va_null_char(va_list args)
{
	char *ptr;

	ptr = va_arg(args, char *);
	if (!ptr)
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
	return (ptr);
}
