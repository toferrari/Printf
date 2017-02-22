/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/22 16:24:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, uint64_t nb, uint64_t len)
{
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_64(nb));
	*str = ft_strcat(*str, ft_itoa_base64(nb, 10));
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base64(nb, 10) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, uint64_t nb, uint64_t len)
{
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base64(nb, 10) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base64(nb, 10));
	*str = ft_strcat(*str, ft_itoa_base64(nb, 10));
}

static int	ft_convert_len_acc_ll(t_print ptf, uint64_t nb)
{
	int64_t len;

	len = ft_intlen_base64(nb, 10);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.space == 1 || ptf.plus == 1)
		len++;
	return (len);
}

int			ft_flag_llu(t_print ptf, uint64_t nb, char **str)
{
	int64_t		len;
	int			i;

	len = ft_convert_len_acc_ll(ptf, nb);
	ft_realloc_adr_p(str, len, ptf.ret);
	i = ft_convert_signe(str, ptf, nb);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	return (len);
}
