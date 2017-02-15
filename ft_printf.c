/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:23:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/14 19:53:07 by tferrari         ###   ########.fr       */
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
		ret = i;
	}
	if (format[i] && format[i] == '%')
	{
		format += i + 1;
		nb = ft_parse_flag(&format, arg, str);
		ret += ft_parse(format, arg, ret + nb, str);
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
	ft_putstr(str);
	va_end(arg);
	return (ret);
}
