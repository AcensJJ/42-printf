/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_stru.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 13:34:53 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 14:05:07 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void		ft_config_stru1(t_bool *struc, char *ptr, char format)
{
	int		notdot;

	notdot = 0;
	format == 's' && struc->print == -1 && struc->zero != -1 ?
	struc->print = struc->zero : 0;
	format != 's' ? struc->space = struc->print : 0;
	format == 'd' && ptr[0] == '-' && struc->zero == -1 ? notdot = 1 : 0;
	format != 's' ? struc->print = (int)ft_strlen(ptr) : 0;
	format != 's' &&
	struc->zero < struc->print ? struc->zero = (int)ft_strlen(ptr) : 0;
	(format == 'x' || format == 'X') && struc->zero != -1 &&
	struc->print == -1 ? struc->space = struc->print : 0;
	(format == 'x' || format == 'X') && struc->zero != -1 ?
	struc->zero = struc->print : 0;
	struc->print == -1 ? struc->print = (int)ft_strlen(ptr) : 0;
	struc->zero == -1 ? struc->zero = struc->print : 0;
	struc->space < struc->zero ? struc->space = struc->zero : 0;
	notdot == 1 ? struc->zero -= 1 : 0;
}

void		ft_config_stru2(int *valprintf, t_bool *struc, char *ptr, char format)
{
	format == 'c' && ptr[0] == '\0' ? struc->space -= 1 : 0;
	format == 'c' && ptr[0] == '\0' ? struc->print += 1 : 0;
	struc->left != 1 && ptr[0] == '-' ? struc->space -= 1 : 0;
	struc->left != 1 && ptr[0] == '-' ? *valprintf += 1 : 0;
}
