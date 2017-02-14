/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/14 10:59:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_h(unsigned int n, int up)
{
	int		len;
	int		end;
	int		i;
	char	*s;

	len = ft_intlen_h(n);
	up = (up == 1) ? 55 : 87;
	i = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	end = len;
	while (i < len)
	{
		if (n % 16 <= 9)
			s[len - 1] = n % 16 + 48;
		else
			s[len - 1] = n % 16 + up;
		n = n / 16;
		len--;
	}
	s[end] = '\0';
	up = 0;
	return (s);
}
