/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/09 17:56:50 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_flag_c_null(t_print ptf, char **format, char **str)
{
	int		len;
	char	c;

	len = 1;
	c = (*format)[-1];
	if (ptf.accuracy > 1 || ptf.zero > 1)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	ft_realloc_adr_p(str, len, ptf.ret);
	if (ptf.moins == 1)
	{
		*str = ft_strnccat(*str, c, 1);
		*str = ft_strnccat(*str, ' ', len - 1);
	}
	else
	{
		if (ptf.zero > 0)
			*str = ft_strnccat(*str, ' ', len - 1);
		else if (ptf.accuracy > 0)
			*str = ft_strnccat(*str, '0', len - 1);
		*str = ft_strnccat(*str, c, 1);
	}
	return (len);
}
