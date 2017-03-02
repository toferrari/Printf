/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/02 21:58:58 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_convert_len_acc(t_print ptf, int len)
{
	int ret;

	ret = len;
	if (len == 0 && ptf.zero == 0)
			return (0);
	if (ptf.zero > len || (ptf.bool_acc != 1 && ptf.accuracy > len)
	|| (ptf.bool_acc == 1 && ptf.accuracy < len))
		ret = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.bool_acc == 1 && ptf.accuracy < len && ptf.zero == 0)
		ret--;
	if (ptf.zero > len && ptf.zero < ptf.accuracy)
		ret = ptf.zero;
	return (ret);
}

int			ft_flag_wstr(t_print ptf, wchar_t *src, char **str)
{
	int		ret;
	char	*dest;
	char	*tmp;
	int		i;
	int		len;

	if (!src)
	{
		ft_realloc_adr_p(str, 6, ptf.ret);
		*str = ft_strcat(*str, "(null)");
		return (6);
	}
	ret = ft_convert_len_acc(ptf, ft_wstr_len(src));
	ft_realloc_adr_p(str, ret, ptf.ret);
	i = 0;
	len = 0;
	dest = ft_strnew(ft_wstr_len(src));
	while (src[i])
	{
		tmp = ft_strnew(ft_wchar_len(src[i]));
		tmp = ft_wchar_to_char(src[i], tmp);
		dest = ft_strcat(dest, tmp);
		ft_memdel((void **)&tmp);
		len += ft_wchar_len(src[i]);
		i++;
	}
	ft_putnbr(i);
	if (ptf.moins == 1)
	{
		if (ptf.accuracy > 0 && ft_strlen(dest) > 0)
		{
			*str = ft_strnccat(*str, '0', ptf.accuracy - ft_strlen(dest));
			*str = ft_strncat(*str, dest, ptf.accuracy);
			*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
		}
		else
		{
			*str = ft_strcat(*str, dest);
			*str = ft_strnccat(*str, ' ', ptf.zero - ft_strlen(dest));
		}
	}
	else
	{
		if (ptf.zero > 0 && ft_strlen(dest) > 0 && ft_strlen(dest) >
		(size_t)ptf.accuracy && ptf.bool_acc == 1)
			*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
		/*else if (ptf.zero > 0 && ft_strlen(dest) > 0 && ft_strlen(dest) >
		(size_t)ptf.accuracy && ptf.bool_acc == 1)
				*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);*/
		else if (ptf.zero > 0 && ft_strlen(dest) > 0)
			*str = ft_strnccat(*str, ' ', ptf.zero - (ft_strlen(dest)));
		else
			*str = ft_strnccat(*str, ' ', ptf.zero);
		if (ptf.accuracy > 0 && ft_strlen(dest) > 0 && ptf.bool_acc != 1)
		{
			*str = ft_strnccat(*str, '0', ptf.accuracy - ft_strlen(dest));
			*str = ft_strncat(*str, dest, ptf.accuracy);
		}
		else if (ptf.bool_acc == 1)
			*str = ft_strncat(*str, dest, ptf.accuracy);
		else
			*str = ft_strcat(*str, dest);
	}
	return (ret);
}
