/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 10:51:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 16:23:26 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void)
{
	//base
	printf("TEST N1\n");
		printf("test|%*d|\n",  1,  22);
		printf("test|%*d|\n",  2,  22);
		printf("test|%*d|\n",  3,  22);
		printf("test|%*d|\n",  10,  22);

	// .
	printf("\nTEST N2\n");
		printf("test|%*.*d|\n",  10,  5, 22);
		printf("test|%.*d|\n",  10,  5);
		printf("test|%-*d|\n",  10,  5);

	// 0
	printf("\nTEST N3\n");
		printf("test|%07d|\n", 22);
		printf("test|%1.7d|\n", 22);
		printf("test|%7d|\n", 22);
		printf("test|%0*d|\n", 10, 22);
		printf("test|%.*d|\n", 10, 22);
		printf("test|%*.*d|\n", 10, 5, 22);

	// multi %
	printf("\nTEST N4\n");
		printf("test|%%d|\n", 22);
		printf("test|%%%d|\n", 22);
		printf("test|%msswq  %%s %%sw %d|\n", 22);

	// hexa
	printf("\nTEST N5\n");
		printf("test|%x|\n", 2209);
		printf("test|%X|\n", 2209);

	// b z
	printf("\nTEST N6\n");
		printf("test|%9d|\n", 10);
		printf("test|%*d|\n", 10, 10);
		printf("test|%18.*d|\n", 5, 10);
		printf("test|%18.07d|\n", 10);
		printf("test|%18.7d|\n", 10);
		printf("test|%*.0d|\n", 10, 10);
		printf("test|%18.5d|\n", 10);
		printf("test|%18*d|\n", 5, 10);
		printf("test|%*18d|\n", 5, 10);

	// fake
	printf("\nTEST N7\n");
		printf("test|%y|\n", 10);
		printf("test|%5y|\n", 10);
		printf("test|%yedfe 5|\n", 10);
		printf("test|%msswq  %%s %%sw %d|\n", 22);

	// more
	printf("\nTEST N8\n");
		printf("test|%10.5d|\n", 1);
		printf("test|%10.5d|\n", 10);
		printf("test|%10.5y|\n", 10);
		printf("test|%10.5ydsdsdsds|\n", 10);
		printf("test|%10y|\n", 10);

	// NULL
	printf("\nTEST N9\n");
		printf("test|%s|\n", NULL);

	// u
	printf("\nTEST N10\n");
		printf("test|%u|\n", 78);
		
	// .0
	printf("\nTEST N11\n");
		printf("test|%.d|\n", 0);
		printf("test|%.s|\n", 0);
		printf("test|%.c|\n", 0);
		printf("test|%.p|\n", 0);
		printf("test|%p|\n", 0144511);
		printf("test|%.d|\n", 9);

	// 1234567890
	printf("\nTEST N11\n");
		printf("test|%10p|\n", 0144511);
		printf("test|%010p|\n", 0144511);
		printf("test|%10.5p|\n", 0144511);
		printf("test|%010.5p|\n", 0144511);

	// -
	printf("\nTEST N12\n");
		printf("test|%-.*d|\n",  10,  5, 22);
		printf("test|%-.*d|\n",  5,  10, 22);
		printf("test|%d|\n",  10,  5);
		printf("test|%-*d|\n",  10,  5);
		printf("test|%-12d|\n",  10,  5);

	printf("\nTEST N13\n");
		//printf("test|%*10.*5d|\n", 22);
		printf("test|%-10d|\n",  5);
		printf("test|%-*d|\n",  10,  5);
		printf("test|%-12d|\n",  10,  5);
		printf("test|%-01.5d|\n",  5);
		printf("test|%-010d|\n",  5);

	// % more
	printf("\nTEST N14\n");
		printf("test|%dewsd|\n", 22);
		printf("test|%dew%dsd|\n", 22, 23);
		printf("test|%dew%ds%%d%d|\n", 22, 23, 24);
		printf("test|%d%ds%%d%d|\n", 22, 11, 24);
		printf("test|%d%%%ds%%d%d|\n", 22, 11, 24);
	return (0);
}