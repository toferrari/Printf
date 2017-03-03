/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:51:19 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/03 15:09:03 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdarg.h>
#include "libft.h"

static void	ft_flag(char ***format, t_print *s_ptf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((**format)[i] && ((**format)[i] == '#' || (**format)[i] == '-' || (**format)[i] == '+'
	|| (**format)[i] == ' ' || ft_isdigit((**format)[i])))
	{
		if ((**format)[i] == '#')
			s_ptf->htag = 1;
		else if ((**format)[i] == '-')
			s_ptf->moins = 1;
		else if ((**format)[i] == '+')
			s_ptf->plus = 1;
		else if ((**format)[i] == ' ')
			s_ptf->space = 1;
		else if (ft_isdigit((**format)[i]))
			s_ptf->zero = s_ptf->zero * 10 + ((**format)[i] - '0');
		i++;
	}
	while (!(ft_isdigit((**format)[j])))
		j++;
	if (((**format)[j] == '0' && (**format)[i] != '.' && s_ptf->moins == 0) ||
	((**format)[j] == '0' && (**format)[i] == '.' && ft_strchr("cC", s_ptf->c)))
	{
		s_ptf->accuracy = s_ptf->zero;
		s_ptf->zero = 0;
	}
	**format += i;
}

static void	ft_accuracy(char **format, t_print *s_ptf)
{
	int i;

	i = 0;
	if (((*format)[i] && (*format)[i] == '.' && s_ptf->accuracy == 0) ||
	((*format)[i] && (*format)[i] == '.' && (*format)[i + 1] == 'c'))
	{
		s_ptf->bool_acc = 1;
		i++;
		while (ft_isdigit((*format)[i]))
		{
			s_ptf->accuracy = s_ptf->accuracy * 10 + ((*format)[i] - '0');
			i++;
		}
		if (ft_strchr("%", (*format)[i]))
			s_ptf->accuracy = 0;
		*format += i;
	}
}

static void	ft_length(char **format, t_print *s_ptf)
{
	int i;

	i = 0;
	while ((*format)[i] && ((*format)[i] == 'l' || (*format)[i] == 'h'
	|| (*format)[i] == 'L' || (*format)[i] == 'j'  || (*format)[i] == 'z'))
	{
		if ((*format)[i] == 'l')
			s_ptf->l++;
		else if ((*format)[i] == 'h')
			s_ptf->h++;
		else if ((*format)[i] == 'L')
			s_ptf->L_flag = 1;
		else if ((*format)[i] == 'j')
			s_ptf->j = 1;
		else if ((*format)[i] == 'z')
			s_ptf->z = 1;
		i++;
	}
	*format += i;
	if (s_ptf->l > 0)
		s_ptf->l = (s_ptf->l % 2 == 0) ? 2 : 1;
	if (s_ptf->h > 0)
		s_ptf->h = (s_ptf->h % 2 == 0) ? 2 : 1;
}

static void	ft_convert(char **format, t_print *s_ptf)
{
	if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAnbrk%", (*format)[0]))
		s_ptf->c = *format[0];
	*format += 1;
}

int			ft_parse_flag(char **format, va_list *arg, char **str, int ret)
{
	t_print argument;
	int len_flag;

	len_flag = 0;
	ft_bzero(&argument, sizeof(argument));
	argument.ret = ret;
	ft_flag(&format, &argument);
	ft_accuracy(format, &argument);
	ft_length(format, &argument);
	ft_flag(&format, &argument);
	ft_convert(format, &argument);
	len_flag = ft_call_arg(arg, str, argument, format);
	argument.ret = ret + len_flag;
	return (len_flag);
}
