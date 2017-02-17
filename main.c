/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:05:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/17 11:15:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "include/ft_printf.h"
#include <limits.h>

int main(void)
{
	int i = 2147483647;
	unsigned int l = 39;
	//short s = 9888888888;
	int n = 748548;
	uintmax_t l2 = 5;
	float f = 10.2;
	//unsigned long long ULLONG_MAX = 18446744073709551615;
	int64_t u = 5;
	char t[50] = "salut tu vas bien?";
	i = 0;
	char c = 'f';

	//t = ft_strdup("salut tu vas bien?");

    //i = printf("%1.1d\n", l);
	//printf("%S", L"Some String");
	//i = printf("le vrai :%c", c);
	printf("le vrai :");
	i = printf("%o, %ho, %hho", -42, -42, -42);
	printf("\ni_vrai = %d", i);
	ft_putstr("le mien :");
	i = ft_printf("%o, %ho, %hho", -42, -42, -42);
	ft_putchar('\n');
	ft_putstrnbr("i_mien = ", i);
	//i = printf("\n%hhd\n", SHRT_MAX);
//	ft_putchar('\n');
//	ft_putstrnbr("ret = ", i);
    return 0;
}
