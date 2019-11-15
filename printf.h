/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 14:39:52 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 17:00:00 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_bool
{
	int				left;
	int				pre;
	int				zero;
	int				pre_star;
	char			arg;
}					t_bool;

int					ft_printf(const char *format, ...)
	 __attribute__((format(printf,1,2)));
void				*ft_do_flag(va_list args, char format, int *sign);
void    			init_struct(t_bool *new);
#endif
