/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:23:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/02 14:33:07 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int			ft_parse(char *format, va_list *arg, int ret, char **str)
{
	int i;
	char *find_percent;
	int nb;

	i = 0;
	find_percent = ft_strchr(format, '%');
	if (find_percent == NULL)
		return (ret += ft_putstrlen(format));
	if (format[i] != '%')
	{
		while (format[i] && format[i] != '%')
			i++;
		*str = ft_strsub(format, 0, ret = i);
	}
	if (format[i] == '%' && format[i + 1] == '%')
	{
		ft_realloc_adr(str, 1);
		//ft_putchar('%');
		*str = ft_strcat(*str, "%");
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
	t_print *flags;
	int ret;
	char *str;

	va_start(arg, format);
	ret = ft_parse(format, &arg, 0, &str);
	ft_putstr(str);
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
	i = ft_printf("salut%%toi%-3058.5482d");
//	ft_putchar('\n');
//	ft_putstrnbr("ret = ", i);
    return 0;
}
