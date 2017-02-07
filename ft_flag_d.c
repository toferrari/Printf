/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/07 13:17:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/libft.h"

int		ft_flag_d(t_print ptf, int nb, char **str)
{
	int		ret;
	int		len;
	char	*tmp;

	ret = 0;
	len = (ptf.zero == 0) ? ft_intlen(nb) : ptf.zero;
	if (!(tmp = ft_strnew(len)))
		return (0);
	ft_realloc_adr(str, len);
	if (ptf.zero != 0)
	{
		ft_strputnchr(&tmp, ' ', len - ft_intlen(nb));
		if (ptf.moins == 1)
			*str = ft_strcat(*str, ft_strcat(ft_itoa(nb), tmp));
		else
			*str = ft_strcat(*str, ft_strcat(tmp, ft_itoa(nb)));
	}
	else
		*str = ft_strcat(*str, ft_itoa(nb));
	return (len);
}
