/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/10 17:04:47 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_u64(uint64_t n)
{
	uint64_t	len;
	uint64_t	end;
	uint64_t	i;
	char		*s;

	len = ft_intlen_uintmax(n);
	i = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	end = len;
	while (i < len)
	{
		s[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	s[end] = '\0';
	return (s);
}
