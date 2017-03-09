/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:05:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/09 18:55:26 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "include/ft_printf.h"
#include <limits.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	int i ;
	unsigned int l = 39;
	//short s = 9888888888;
	int n = 748548;
	uintmax_t l2 = 5;
	float f = 10.2;
	//unsigned long long ULLONG_MAX = 18446744073709551615;
	int64_t u = 5;
	char t[50];
	//char c = 'f';
	int j;

	//t = ft_strdup("salut tu vas bien?");

    //i = printf("%1.1d\n", l);
	//printf("%S", L"Some String");
	//i = printf("le vrai :%c", c);
	wchar_t b = L'ބ';
	int a;
	a = (int)b;
	t[0] = b;
	printf("le vrai :");
	i = printf("%zj", "9223372036854775807");
	printf("\ni_vrai = %d\n", i);
	ft_putstr("le mien :");
	j = ft_printf("%zj", "9223372036854775807");
	ft_putchar('\n');
	ft_putstrnbr("i_mien =", j);
	//ft_putchar('\n');
	//a = (int)b;
	//printf("\na = %s", ft_itoa_base(a, 16));
/*	char c;
	c = 0xe7;
	write(1, &c, 1);
	c = 0x8c;
	write(1, &c, 1);
	c = 0xab;
	write(1, &c, 1);*/
	//i = printf("\n%hhd\n", SHRT_MAX);
//	ft_putchar('\n');
//	ft_putstrnbr("ret = ", i);
    return 0;
}
