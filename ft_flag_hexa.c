/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:40:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/15 14:44:38 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, unsigned int nb, int i)
{
	if (i == 2 && nb != 0)
		*str = (ptf.c == 'X') ? ft_strcat(*str, "0X") : ft_strcat(*str, "0x");
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_h(nb));
	if (nb > 0)
		*str = (ptf.c == 'X') ?  ft_strcat(*str, ft_itoa_h(nb, 1)) :
		ft_strcat(*str, ft_itoa_h(nb, 0));
	if (ptf.accuracy < ptf.zero)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_h(nb) - i);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - i);
}

static void	ft_moin_off(char **str, t_print ptf, unsigned int nb, int i)
{
	int len;

	len = (nb == 0) ? 0 : ft_intlen_h(nb);
	if (ptf.accuracy < ptf.zero)
		*str = ft_strnccat(*str, ' ', ptf.zero - len - i);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - i);
	if (i == 2 && nb != 0)
		*str = (ptf.c == 'X') ? ft_strcat(*str, "0X") : ft_strcat(*str, "0x");
	if (ptf.accuracy > 0 && nb != 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len - i);
	if (!(nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0))
		*str = (ptf.c == 'X') ?  ft_strcat(*str, ft_itoa_h(nb, 1)) :
		ft_strcat(*str, ft_itoa_h(nb, 0));
}

static int	ft_convert_len_acc(t_print ptf, unsigned int nb)
{
	int len;

	if (nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0 && ptf.zero == 0)
		return (0);
	len = ft_intlen_h(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.accuracy == 0 && ptf.zero == 0 && ptf.htag == 1 && nb != 0)
		len += 2;
	return (len);
}

int			ft_flag_hexa(t_print ptf, unsigned int nb, char **str)
{
	int len;
	int i;

	len = ft_convert_len_acc(ptf, nb);
	ft_realloc_adr(str, len);
	i = (ptf.htag == 1) ? 2 : 0;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	return (len);
}
