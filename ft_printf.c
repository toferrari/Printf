/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:23:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/11 17:10:45 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "include/ft_printf.h"

static int	ft_0_pourcent(char **str, char *format)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(format);
	ft_realloc_adr(str, len);
	*str = ft_strcat(*str, format);
	return (len);
}

static int	ft_parse(char *format, va_list *arg, int ret, char **str)
{
	int i;
	char *find_percent;
	int nb;

	i = 0;
	if (*str == NULL)
		*str = ft_strnew(1);
	if (!(find_percent = ft_strchr(format, '%')))
		return (ret += ft_0_pourcent(str, format));
	if (format[i] != '%')
	{
		ft_realloc_adr(str, i = ft_strclen(format, '%'));
		*str = ft_strccat(*str, format, '%');
	}
	if (format[i] && format[i] == '%')
	{
		format += i + 1;
		nb = ft_parse_flag(&format, arg, str);
		ret = ft_parse(format, arg, ret + nb, str);
	}
	return (ret);
}

int			ft_printf(char *format, ...)
{
	va_list	arg;
	int ret;
	char *str = NULL;

	va_start(arg, format);
	ret = ft_parse(format, &arg, 0, &str);
	ft_putendl(str);
	va_end(arg);
	return (ret);
}

int main(void)
{
	long i = -1407346244;
	int l = 3147483647;
	//short s = 9888888888;
	uintmax_t l2 = 5;
	float f = 10.2;
	unsigned long long h = 18446744073709551;
	int64_t u = 5;
	//char test[] = "";
	i = 0;
	char c = 49;

	//test = ft_strdup("salut tu vas bien?");

    //i = printf("%1.1d\n", l);
	i = printf("le vrai :%-010%");
	//i = printf("%10.50d", l);
	i = ft_printf("le mien :%-010%", l);
	//ft_putnbr(i);
//	ft_putchar('\n');
//	ft_putstrnbr("ret = ", i);
    return 0;
}
