/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/11 11:29:41 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_u(unsigned int n)
{
	int		len;
	int		end;
	int		i;
	char	*s;

	len = ft_intlen_u(n);
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
