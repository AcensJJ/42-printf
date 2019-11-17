/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:03:32 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 17:49:01 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/include/get_next_line.h"
#include "./libft/include/libft.h"

int		ft_end_one_check(int *sign, t_bool *struc, int i)
{
	free(struc->arg);
	free(struc);
	if (*sign == -1)
	{
		free(sign);
		return (-1);
	}
	return (i);
}
