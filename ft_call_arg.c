/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:31:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/11 17:03:11 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_call_arg(va_list *arg, char **str, t_print ptf)
{
	if ((ptf.l > 0 || ptf.j == 1) && ft_strchr("dDi", ptf.c))
		return (ft_flag_lld(ptf, (int64_t)va_arg(*arg, long long), str));
	else if (ft_strchr("dDi", ptf.c) || (ft_strchr("dDi", ptf.c) && ptf.h == 1))
		return (ft_flag_d(ptf, va_arg(*arg, int), str));
	else if ((ptf.l > 0 || ptf.j == 1) && ft_strchr("uU", ptf.c))
		return (ft_flag_llu(ptf, (uint64_t)va_arg(*arg, long long), str));
	else if (ft_strchr("Uu", ptf.c) || (ft_strchr("uU", ptf.c) && ptf.h == 1))
		return (ft_flag_u(ptf, va_arg(*arg, unsigned int), str));
	else if (ptf.c == '%')
		return (ft_flag_pourcent(ptf, str));
	/*if (ft_strchr("sS", ptf.c))
		return (ft_flag_char(arg, va_arg(*arg, int), str));*/
	return (0);
}
