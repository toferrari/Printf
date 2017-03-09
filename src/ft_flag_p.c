/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:40:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/08 18:15:54 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, uint64_t nb, int i)
{
	if (i == 2)
		*str = (ptf.c == 'X') ? ft_strcat(*str, "0X") : ft_strcat(*str, "0x");
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base64(nb, 16));
	*str = ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base64(nb, 16) - i);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - i);
}

static void	ft_moin_off(char **str, t_print ptf, uint64_t nb, int i)
{
	*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base64(nb, 16) - i);
	if (i == 2)
		*str = ft_strcat(*str, "0x");
	if (ptf.accuracy > 0 && nb != 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base64(nb, 16));
	else
		*str = ft_strnccat(*str, '0', ptf.accuracy);
	if ((nb == 0 && ptf.bool_acc == 0) || (nb != 0))
		*str = ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc(t_print ptf, uint64_t nb)
{
	int len;

	if ((nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0))
		return (2);
	len = ft_intlen_base64(nb, 16);
	if (ptf.c == 'p' && ptf.zero < ft_intlen_base64(nb, 16) + 2)
		len += 2;
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.accuracy >= len && ptf.bool_acc == 1)
		len += 2;
	return (len);
}

int			ft_flag_p(t_print ptf, uint64_t nb, char **str)
{
	int len;
	int i;

	len = ft_convert_len_acc(ptf, nb);
	ptf.tmp = ft_itoa_base64(nb, 16);
	ft_realloc_adr_p(str, len, ptf.ret);
	i = (ptf.c == 'p') ? 2 : 0;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}