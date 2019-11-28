/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:03:32 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 11:35:37 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void		ft_print_pre(int *valprintf, t_bool *struc, char *ptr, char format)
{
	char	c;

	c = 0;
	struc->left != 1 ? ft_print_space(valprintf, struc) : 0;
	if (struc->zero > 0 && format != 's')
	{
		ft_print_zero(valprintf, struc, ptr, format);
		if (ptr[0] == '-')
			ptr++;
	}
	format == 'c' && ptr[0] == '\0' ? write(1, &c, 1) :
	write(1, ptr, struc->print);
	*valprintf += struc->print;
	if (struc->left == 1)
		ft_print_space(valprintf, struc);
}

void		ft_end_one_check(t_bool *struc)
{
	struc->arg = NULL;
	free(struc);
	struc = NULL;
}

t_bool		*ft_set_struct(t_bool *struc)
{
	if (!(struc = malloc(sizeof(*struc))))
		return (NULL);
	struc->space = 0;
	struc->zero = 0;
	struc->left = 0;
	struc->print = -1;
	struc->arg = NULL;
	return (struc);
}
