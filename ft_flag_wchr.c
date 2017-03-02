/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_wchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/02 17:40:39 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <locale.h>

static int	ft_convert_len_acc(t_print ptf, int len)
{
	if (ptf.zero == 0 && ptf.accuracy > 0 && ptf.bool_acc == 1)
		return (len);
	if ((ptf.zero > 1 || ptf.accuracy > 1))
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	return (len);
}

int			ft_flag_wchr(t_print ptf, wchar_t c, char **str)
{
	int		chr_len;
	char	*dest;
	int		len;

	setlocale(LC_ALL,"");
	chr_len = ft_wchar_len(c);
	dest = ft_strnew(chr_len);
	len = ft_convert_len_acc(ptf, chr_len);
	ft_realloc_adr_p(str, chr_len + len, ptf.ret);
	dest = ft_wchar_to_char(c, dest);
	if (ptf.moins == 1)
	{
		if (ptf.accuracy > 0)
		{
			*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy);
			*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - ptf.accuracy);
			len = (ptf.zero > ptf.accuracy) ? ptf.zero : len - ptf.accuracy;
		}
		else
			{*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - 1);}
	}
	else
	{
		if (ptf.zero > 0)
			*str = ft_strlnccat(*str, ' ', &ptf.ret,
			ptf.zero  - ptf.accuracy - 1);
		else
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero);
		if (ptf.accuracy > 0 && c && ptf.bool_acc == 0)
		{
			*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy - 1);
			*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
		}
		else
			*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
	}
	ft_memdel((void **)&dest);
	return (chr_len);



	/*int len;

	if (!c && ptf.zero == 0)
		return (1);
	len = ft_convert_len_acc(ptf);
	ft_realloc_adr_p(str, len, ptf.ret);
	if (ptf.moins == 1)
	{
		if (ptf.accuracy > 0)
		{
			*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy);
			*str = ft_strlnccat(*str, c, &ptf.ret, 1);
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - ptf.accuracy);
			len = (ptf.zero > ptf.accuracy) ? ptf.zero : len - ptf.accuracy;
		}
		else
			{*str = ft_strlnccat(*str, c, &ptf.ret, 1);
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - 1);}
	}
	else
	{
		if (ptf.zero > 0)
			*str = ft_strlnccat(*str, ' ', &ptf.ret,
			ptf.zero  - ptf.accuracy - 1);
		else
			*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero);
		if (ptf.accuracy > 0 && c && ptf.bool_acc == 0)
		{
			*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy - 1);
			*str = ft_strlnccat(*str, c, &ptf.ret, 1);
		}
		else
			*str = ft_strlnccat(*str, c, &ptf.ret, 1);
	}
	return (len);*/
}
