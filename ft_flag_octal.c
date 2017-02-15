/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:09:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/15 14:40:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, unsigned int nb, int i)
{
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_o(nb));
	if (ptf.accuracy == 0 && i == 1)
		*str = ft_strcat(*str, "0");
	*str = ft_strcat(*str, ft_itoa_o(nb));
	if (ptf.accuracy > 0 && ptf.zero > 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
	else if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_o(nb) - i);
}

static void	ft_moin_off(char **str, t_print ptf, unsigned int nb, int i)
{
	int len;

	len = (nb == 0) ? 0 : ft_intlen_o(nb);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - len - i);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
	if (ptf.accuracy > 0 && nb != 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
	if (ptf.accuracy == 0 && i == 1)
		*str = ft_strcat(*str, "0");
	if (nb != 0)
		*str = ft_strcat(*str, ft_itoa_o(nb));
	else if (nb == 0 && ptf.zero == 0 && ptf.accuracy == 0 && ptf.bool_acc == 0)
		*str = ft_strcat(*str, ft_itoa_o(nb));
}

static int	ft_convert_len_acc(t_print ptf, unsigned int nb)
{
	int len;

	if (nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0 && ptf.zero == 0)
		return (0);
	len = ft_intlen_o(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	return (len);
}

int			ft_flag_octal(t_print ptf, unsigned int nb, char **str)
{
	int len;
	int i;

	len = ft_convert_len_acc(ptf, nb);
	ft_realloc_adr(str, len);
	if (ptf.accuracy == 0 && ptf.zero == 0 && ptf.htag == 1)
		len++;
	i = ptf.htag;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	return (len);
}
