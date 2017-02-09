/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:51:19 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/09 16:38:33 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdarg.h>
#include "libft.h"

static void	ft_flag(char ***format, t_print *s_ptf)
{
	int i;

	i = 0;
	if ((**format)[i] && ((**format)[i] == '#' || (**format)[i] == '-' || (**format)[i] == '+'
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
		**format += (i + 1);
		ft_flag(format, s_ptf);
	}
}

static void	ft_accuracy(char **format, t_print *s_ptf)
{
	int i;

	i = 0;
	if ((*format)[i] && (*format)[i] == '.')
	{
		s_ptf->bool_acc = 1;
		i++;
		while (ft_isdigit((*format)[i]))
		{
			s_ptf->accuracy = s_ptf->accuracy * 10 + ((*format)[i] - '0');
			i++;
		}
		*format += i;
	}
}

static void	ft_length(char **format, t_print *s_ptf)
{
	int i;

	i = 0;
	while ((*format)[i] && (((*format)[i] == 'l') || (*format)[i] == 'h' || (*format)[i] == 'L'))
	{
		if ((*format)[i] == 'l')
			s_ptf->l++;
		else if ((*format)[i] == 'h')
			s_ptf->h++;
		else if ((*format)[i] == 'L')
			s_ptf->L = 1;
		i++;
	}
	*format += i;
	s_ptf->l = (s_ptf->l % 2 == 0) ? 2 : 1;
	s_ptf->h = (s_ptf->h % 2 == 0) ? 2 : 1;
}

static void	ft_convert(char **format, t_print *s_ptf)
{
	if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAnbrk%", *format[0]))
		s_ptf->c = *format[0];
	*format += 1;
}

int			ft_parse_flag(char **format, va_list *arg, char **str)
{
	t_print argument;
	int len_flag;

	len_flag = 0;
	ft_bzero(&argument, sizeof(argument));
	ft_flag(&format, &argument);
	ft_accuracy(format, &argument);
	ft_length(format, &argument);
	ft_flag(&format, &argument);
	ft_convert(format, &argument);
	len_flag = ft_call_arg(arg, str, argument);

	return (len_flag);
}
