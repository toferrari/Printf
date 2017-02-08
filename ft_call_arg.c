/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:31:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/08 18:48:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_call_arg(va_list *arg, char **str, t_print ptf)
{
	if (ft_strchr("d", ptf.c))
		return (ft_flag_int(argument, va_arg(*arg, int), str));
	if (ft_strchr("sS", ptf.c))
		return (ft_flag_char(argument, va_arg(*arg, int), str));
}
