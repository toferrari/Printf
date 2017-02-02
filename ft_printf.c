/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:23:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/02 17:33:40 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/libft.h"
#include "include/ft_printf.h"

int			ft_parse(char *format, va_list *arg, int ret, char **str)
{
	int i;
	char *find_percent;
	int nb;

	i = 0;
	if (*str == NULL)
		*str = ft_strnew(1);
	if (!(find_percent = ft_strchr(format, '%')))
		return (ret += ft_putstrlen(format));
	if (format[i] != '%')
	{
		ft_realloc_adr(str, i = ft_strclen(format, '%'));
		*str = ft_strccat(*str, format, '%');
	//	ft_putendl(*str);
	}
	if (format[i] == '%' && format[i + 1] == '%')
	{
		ft_realloc_adr(str, 1);
		*str = ft_strcat(*str, "%");
		//ft_putendl(*str);
		ret = ft_parse(format + (i + 2), arg, ret + 1, str);
	}
	else if (format[i] && format[i] == '%')
	{
		format += i + 1;
		nb = ft_parse_flag(&format, arg);
		ret = ft_parse(format, arg, ret + nb, str);
	}
	return (ret);
}

static int		ft_printf(char *format, ...)
{
	va_list	arg;
	int ret;
	char *str = NULL;

	va_start(arg, format);
	ret = ft_parse(format, &arg, 0, &str);
	//ft_putstr(str);
	return (ret);
}

int main(void)
{
	int i;
	int l = 170;
	char *test;
	i = 0;
	char c = '9';

	test = ft_strdup("salut tu vas bien?");

    //i = printf("%d", l);
	i = ft_printf("salut%%toi%-3058.5482lld");
//	ft_putchar('\n');
//	ft_putstrnbr("ret = ", i);
    return 0;
}
