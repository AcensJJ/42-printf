/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:03:32 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 13:36:40 by jacens      ###    #+. /#+    ###.fr     */
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
	while ((struc->space - struc->zero) != i)
	{
		write(1, " ", 1);
		*valprintf += 1;
		i++;
	}
}

void		ft_print_pre(int *valprintf, t_bool *struc, char *ptr, char format)
{
	char	c;

	c = 0;
	if (struc->left != 1)
	{
		format == 'd' && ptr[0] == '-' ? *valprintf -= 1 : 0;
		ft_print_space(valprintf, struc);
	}
	if (struc->zero != 1 && format != 'x' && format != 'X')
	{
		ft_print_zero(valprintf, struc, ptr);
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
	struc->space = -1;
	struc->zero = -1;
	struc->left = -1;
	struc->print = -1;
	struc->arg = NULL;
	return (struc);
}
