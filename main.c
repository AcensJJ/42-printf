/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 10:51:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 16:50:14 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("TEST N1\n");
	printf("test|%*d|\n",  1,  22);
	printf("test|%*d|\n",  2,  22);
	printf("test|%*d|\n",  3,  22);
	printf("test|%*d|\n",  10,  22);
	printf("\nTEST N2\n");
	printf("test|%*.*d|\n",  10,  5, 22);
	printf("test|%.*d|\n",  10,  5);
	printf("test|%-*d|\n",  10,  5);
	printf("\nTEST N3\n");
	printf("test|%07d|\n", 22);
	printf("test|%1.7d|\n", 22);
	printf("test|%7d|\n", 22);
	printf("test|%0*d|\n", 10, 22);
	printf("test|%.*d|\n", 10, 22);
	printf("test|%*.*d|\n", 10, 5, 22);
	printf("\nTEST N4\n");
	printf("test|%%d|\n", 22);
	printf("test|%%%d|\n", 22);
	printf("test|%msswq  %%s %%sw %d|\n", 22);
	printf("\nTEST N5\n");
	printf("test|%x|\n", 2209);
	printf("test|%X|\n", 2209);
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
	printf("\nTEST N6\n");
	printf("test|%y|\n", 10);
	printf("test|%yedfe 5|\n", 10);
	printf("test|%msswq  %%s %%sw %d|\n", 22);
	printf("\nTEST N6\n");
	printf("test|%10.5d|\n", 10);
	printf("test|%10.5y|\n", 10);
	printf("test|%10y|\n", 10);
	printf("\nTEST N7\n");
	printf("test|%s|\n", NULL);
	printf("\nTEST N8\n");
	printf("test|%u|\n", 78);
	return (0);
}