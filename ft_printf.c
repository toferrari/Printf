/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:23:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/24 13:56:36 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static int		ft_printf(char *format, ...)
{
	int		nb;
	int		i;
	va_list	arg;
	t_print *arguements;

	i = 0;
	nb = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1]|| format[i + 1] != '%'))
			nb++;
		i++;
	}
	if (!(arguements = (t_print*)malloc(sizeof(t_print) * nb)))
		return (0);

	return (1);
}

int main(void)
{
	int i;
	long l = 444;

    i = printf("%d%d%d%d", l, 55, 55, 55);
	ft_putnbrendl(i);
    return 0;
}





/*
int Sum( int elem, ... )
{
   int i;
   int sum = 0;

   va_list pArg;
   va_start( pArg, elem );

   if(elem==0) return 0;

   for(i=0; i<elem; i++)
           sum +=  va_arg(pArg, int);

   va_end(pArg);
   return sum;
}

//---------------------------------------------------------------------------
int main(void)
{
    int Somme = Sum( 3, 30, 40, 50 );
    printf( "La somme est : %d\n", Somme );

    Somme = Sum( 5, 30, 40, 50, 20, 40 );
    printf( "La somme est : %d\n", Somme );


    return 0;
}*/
