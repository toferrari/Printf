/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/15 13:37:39 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_convert_len_acc(t_print ptf, char *src)
{
	int len;

	len = ft_strlen(src);
	if (len == 0 && ptf.zero == 0)
			return (0);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	return (len);
}

int			ft_flag_str(t_print ptf, char *src, char **str)
{
	int len;

	len = ft_convert_len_acc(ptf, src);
	ft_realloc_adr(str, len);
	if (ptf.moins == 1)
	{
		if (ptf.accuracy > 0 && ft_strlen(src) > 0)
		{
			*str = ft_strnccat(*str, '0', ptf.accuracy - ft_strlen(src));
			*str = ft_strncat(*str, src, ptf.accuracy);
			*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
			len = (ptf.zero > ptf.accuracy) ? ptf.zero : len - ptf.accuracy;
		}
		else
			{*str = ft_strcat(*str, src);
			*str = ft_strnccat(*str, ' ', ptf.zero - ft_strlen(src));}
	}
	else
	{
		if (ptf.zero > 0 && ft_strlen(src) > 0)
			*str = ft_strnccat(*str, ' ', ptf.zero - (ft_strlen(src) - ptf.accuracy));
		else
			*str = ft_strnccat(*str, ' ', ptf.zero);
		if (ptf.accuracy > 0 && ft_strlen(src) > 0)
		{
			*str = ft_strnccat(*str, '0', ptf.accuracy - ft_strlen(src));
			*str = ft_strncat(*str, src, ptf.accuracy);
			len = (ptf.zero > ptf.accuracy) ? ptf.zero : len - ptf.accuracy;
		}
		else
			*str = ft_strcat(*str, src);
	}
	return (len);
}
