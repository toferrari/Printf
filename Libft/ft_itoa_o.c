/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/13 16:30:52 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_o(unsigned int n)
{
	int		len;
	int		end;
	int		i;
	char	*s;

	len = ft_intlen_o(n);
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
