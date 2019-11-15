/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pre_printf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 16:59:43 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 16:59:46 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/include/get_next_line.h"
#include "./libft/include/libft.h"

void    init_struct(t_bool *new)
{
    new->left = 0;
    new->pre = 0;
    new->zero = 0;
    new->pre_star = 0;
}
