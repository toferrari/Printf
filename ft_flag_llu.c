/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/11 14:36:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, uint64_t nb, uint64_t len)
{
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_intmax(nb));
	*str = ft_strcat(*str, ft_itoa_u64(nb));
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_uintmax(nb) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, uint64_t nb, uint64_t len)
{
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_uintmax(nb) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_uintmax(nb));
	*str = ft_strcat(*str, ft_itoa_u64(nb));
}

static int	ft_convert_len_acc_ll(t_print ptf, uint64_t nb)
{
	int64_t len;

	len = ft_intlen_uintmax(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.space == 1 || ptf.plus == 1)
		len++;
	return (len);
}

int			ft_flag_llu(t_print ptf, uint64_t nb, char **str)
{
	int64_t		len;

	len = ft_convert_len_acc_ll(ptf, nb);
	ft_realloc_adr(str, len);
	len = ft_convert_signe(str, ptf);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, len);
	else
		ft_moin_off(str, ptf, nb, len);
	return (len);
}
