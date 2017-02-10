/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_len_acc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:08:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/10 13:58:50 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft.h"

int		ft_convert_len_acc(t_print ptf, int nb)
{
	int len;

	len = ft_intlen(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.space == 1 || ptf.plus == 1)
		len++;
	return (len);
}
