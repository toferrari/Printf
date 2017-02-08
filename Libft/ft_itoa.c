/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/02 19:37:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*s;

	len = ft_intlen(n);
	i = 0;
	(n < 0) ? len++ : 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(s = ft_memalloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		i++;
	}
	while (i < len)
	{
		s[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	s[i] = '\0';
	return (ft_reverse_nb(s));
}
