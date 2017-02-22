/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/22 15:40:24 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_convert_len_acc(t_print ptf, char c)
{
	int len;

	len = 1;
	if ((ptf.zero > 1 || ptf.accuracy > 1) && c)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	return (len);
}

int			ft_flag_chr(t_print ptf, char c, char **str)
{
	int len;

	if (!c && ptf.zero == 0)
		return (1);
	len = ft_convert_len_acc(ptf, c);
	ft_realloc_adr_p(str, len, ptf.ret);
	if (ptf.moins == 1)
	{
		if (ptf.accuracy > 0)
		{
			*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy);
			*str = ft_strlnccat(*str, c, &ptf.ret, 1);
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - ptf.accuracy);
			len = (ptf.zero > ptf.accuracy) ? ptf.zero : len - ptf.accuracy;
		}
		else
			{*str = ft_strlnccat(*str, c, &ptf.ret, 1);
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - 1);}
	}
	else
	{
		if (ptf.zero > 0)
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero  - ptf.accuracy - 1);
		else
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero);
		if (ptf.accuracy > 0 && c && ptf.bool_acc == 0)
		{
			*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy - 1);
			*str = ft_strlnccat(*str, c, &ptf.ret, 1);
		}
		else
			*str = ft_strlnccat(*str, c, &ptf.ret, 1);
	}
	return (len);
}
