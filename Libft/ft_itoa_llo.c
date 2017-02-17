/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/16 18:20:56 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_llo(uint64_t n)
{
	int		len;
	int		end;
	int		i;
	char	*s;

	len = ft_intlen_llo(n);
	i = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	end = len;
	while (i < len)
	{
		s[len - 1] = n % 8 + 48;
		n = n / 8;
		len--;
	}
	s[end] = '\0';
	return (s);
}
