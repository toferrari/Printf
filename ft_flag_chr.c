/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/14 15:40:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_convert_len_acc(t_print ptf)
{
	int len;

	len = 1;
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	return (len);
}

int			ft_flag_chr(t_print ptf, char *c, char **str)
{
	int len;

	len = ft_convert_len_acc(ptf);
	ft_realloc_adr(str, len);
	if (ptf.moins == 1)
	{
		*str = ft_strcat(*str, c);
		*str = ft_strnccat(*str, ' ', ptf.zero - 1);
	}
	else
	{
		if (ptf.zero > 0)
			*str = ft_strnccat(*str, ' ', ptf.zero - 1);
		else if (ptf.accuracy > 0)
			*str = ft_strnccat(*str, '0', ptf.accuracy - 1);
		*str = ft_strcat(*str, c);
	}
	return (len);
}
