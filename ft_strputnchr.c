/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strputnchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:48:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/07 12:12:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/ft_printf.h"

void	ft_strputnchr(char **str, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		(*str)[i] = c;
		i++;
	}
}
