/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_stru.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 13:34:53 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 13:41:44 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void		ft_config_stru(int *valprintf, t_bool *struc, char *ptr,
							char format)
{
	struc->space < 0 ? struc->left = 1 : 0;
	struc->space < 0 ? struc->space *= -1 : 0;
	struc->space == 0 && struc->zero == 0 ? struc->print = 0 : 0;
	format == 's' && struc->zero > 0 && struc->space == 0 ?
	struc->space = struc->zero : 0;
	format == 's' && struc->zero > 0 && struc->space != 0 ?
	struc->print = struc->zero : 0;
	format != 's' && ptr[0] == '-' ? struc->zero += 1 : 0;
	format == 's' && struc->zero > 0 ? struc->zero = 0 : 0;
	format == 's' && struc->space > (int)ft_strlen(ptr) && struc->print != 0 ?
	struc->print = (int)ft_strlen(ptr) : 0;
	format != 's' && struc->print == -1 ?
	struc->print = (int)ft_strlen(ptr) : 0;
	format == 'c' && ptr[0] == '\0' ? struc->space -= 1 : 0;
	format == 'c' && ptr[0] == '\0' ? *valprintf += 1 : 0;
	format != 's' ? struc->zero -= struc->print : 0; 
	format != 's' && struc->zero < 0 ? struc->zero = 0 : 0;
	struc->space -= (struc->print + struc->zero);
}
