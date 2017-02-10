/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_signe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:46:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/10 12:16:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_convert_signe(char **str, t_print ptf)
{
	if (ptf.plus == 1)
		*str = ft_strcat(*str, "+");
	else if (ptf.space == 1)
		*str = ft_strcat(*str, " ");
	return ((ptf.plus == 1 || ptf.space == 1) ? 1 : 0);
}
