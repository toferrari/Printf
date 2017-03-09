/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/09 13:55:43 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_convert_len_acc(t_print ptf, int len)
{
	int		ret;

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

static void	ft_dest(t_print *ptf, wchar_t *src, char **dest)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	while (src[i])
	{
		tmp = ft_strnew(ft_wchar_len(src[i]));
		tmp = ft_wchar_to_char(src[i], tmp);
		*dest = ft_strcat(*dest, tmp);
		ft_memdel((void **)&tmp);
		if (ptf->accuracy > 0 && len + ft_wchar_len(src[i] > ptf->accuracy)
		&& ptf->accuracy < ptf->zero)
		{
			ptf->accuracy += ptf->accuracy - len;
			break ;
		}
		len += ft_wchar_len(src[i]);
		i++;
	}
}

static void	ft_moin_on(char **str, t_print ptf, char *dest, int len)
{
	if (ptf.accuracy > 0 && len > 0)
	{
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
		*str = ft_strncat(*str, dest, ptf.accuracy);
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
	}
	else
	{
		*str = ft_strcat(*str, dest);
		*str = ft_strnccat(*str, ' ', ptf.zero - len);
	}
}

static void	ft_moin_off(char **str, t_print ptf, char *dest, int len)
{
	if (ptf.zero > 0 && len > 0 && len > ptf.accuracy && ptf.bool_acc == 1)
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
	else if (ptf.zero > 0 && len > 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - (len));
	else
		*str = ft_strnccat(*str, ' ', ptf.zero);
	if (ptf.accuracy > 0 && len > 0 && ptf.bool_acc != 1)
	{
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
		*str = ft_strncat(*str, dest, ptf.accuracy);
	}
	else if (ptf.bool_acc == 1)
		*str = ft_strncat(*str, dest, ptf.accuracy);
	else
		*str = ft_strcat(*str, dest);
}

int			ft_flag_wstr(t_print ptf, wchar_t *src, char **str)
{
	int		ret;
	int		len;
	char	*dest;

	if (!src)
	{
		ft_realloc_adr_p(str, 6, ptf.ret);
		*str = ft_strcat(*str, "(null)");
		return (6);
	}
	ret = ft_convert_len_acc(ptf, ft_wstr_len(src));
	ft_realloc_adr_p(str, ret, ptf.ret);
	dest = ft_strnew(ft_wstr_len(src));
	ft_dest(&ptf, src, &dest);
	len = ft_strlen(dest);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, dest, len);
	else
		ft_moin_off(str, ptf, dest, len);
	ft_memdel((void **)&dest);
	return (ret);
}
