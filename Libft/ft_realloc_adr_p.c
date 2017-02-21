/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_adr_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:39:27 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/21 18:52:44 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_realloc_adr_p(char **str, int size, int len)
{
	char		*tmp;

	if (size < 0)
		return (0);
	if (size == 0)
		return (0);
	if (!(tmp = ft_strnew(len)))
		return (0);
	tmp = ft_strcpy(tmp, *str);
	ft_memdel((void **)str);
	if (!(*str = ft_strnew(len + size)))
		return (0);
	*str = ft_strcpy(*str, tmp);
	ft_memdel((void **)&tmp);
	tmp = NULL;
	return (1);
}
