/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 14:39:52 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 15:04:18 by jacens      ###    #+. /#+    ###.fr     */
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
	int				space;
	int				zero;
	int				left;
	int				print;
	char			*arg;
	int				intnull;
	int				dot;
}					t_bool;

int					ft_printf(const char *format, ...)
		 __attribute__((format(printf,1,2)));
int					ft_no_pre(const char *format, va_list args,
								int *valprintf, t_bool *struc);
int					ft_with_pre(const char *format, va_list args,
								int *valprintf, t_bool *struc);
void				ft_end_one_check(t_bool *struc);
t_bool				*ft_set_struct(t_bool *struc);
char				*ft_config_flags(va_list args, char format, int *valprintf,
								t_bool *struc);
char				*ft_va_null_char(va_list args);
int					ft_va_null_int(va_list args, t_bool *struc);
void				ft_print_pre(int *valprintf, t_bool *struc, char *ptr,
								char format);
void				ft_print_zero(int *valprintf, t_bool *struc, char *ptr,
								char format);
void				ft_with_pre_do(char format, int *valprintf, char *ptr,
								t_bool *struc);
void				ft_print_space(int *valprintf, t_bool *struc);
void				ft_config_stru(t_bool *struc, char *ptr);
void				ft_config_stru2(t_bool *struc, char *ptr);
void				ft_config_stru3(int *valprintf, t_bool *struc, char *ptr,
								char format);
void				ft_config_stru4(t_bool *struc, char *ptr, int *valprintf,
								char format);
#endif
