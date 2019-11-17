/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 14:08:20 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 15:02:45 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*int		ft_printf(const char *str, ...)
{
	int		nb;

	while ()
		;
	printf("%s %d\n", str, nb);
	return (0);
}*/

void	pong(va_list *ap)
{
	printf("%d, ", va_arg(*ap, int));
}

void	ping(int num, ...)
{
	va_list ap;

	va_start(ap, num);
	int i = 0;
	int ret = 0;
	while (i < num)
	{
		i % 2 == 0 ? printf("%d, ", va_arg(ap, int)) : pong(&ap);
		i++;
	}
	va_end(ap);
}

int main(void)
{
	// ft_printf("im a test %d, salut %p, ok %s", 1, 2, 3, 4, 5);
	ping(5, 1, 2, 3, 4, 5);
	return (0);
}
