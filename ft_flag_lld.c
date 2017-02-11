/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/11 14:28:17 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, int64_t nb, int64_t len)
{
	uint64_t	unb;

	unb = (nb < 0) ? (uint64_t)-nb : nb;
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_intmax(unb));
	*str = ft_strcat(*str, ft_itoa_u64(unb));
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_uintmax(unb) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, int64_t nb, int64_t len)
{
	uint64_t	unb;

	unb = (nb < 0) ? (uint64_t)-nb : nb;
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_uintmax(unb) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_uintmax(unb));
	*str = ft_strcat(*str, ft_itoa_u64(unb));
}

static int	ft_convert_len_acc_ll(t_print ptf, int64_t nb)
{
	int64_t len;

	len = ft_intlen_intmax(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.space == 1 || ptf.plus == 1)
		len++;
	return (len);
}

int			ft_flag_lld(t_print ptf, int64_t nb, char **str)
{
	int64_t		len;
	int			i;

	len = ft_convert_len_acc_ll(ptf, nb);
	ft_realloc_adr(str, len);
	len = ft_convert_signe(str, ptf);
	len += (nb < 0) ? 1 : 0;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, len);
	else
		ft_moin_off(str, ptf, nb, len);
	return (len);
}
