/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:44:21 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/03 15:09:05 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		ft_flag_color(char **str, t_print *ptf, char ** format)
{
	int i;

	i = 0;
	if (ptf->color == 1)
		ft_strcat_p(*str, "")
	if ((*format)[i] == '{' && ptf->color == 0)
	{
		ptf->color == 1;
		ft_realloc_adr_p();
		if (ft_strnstr(*format))
	}
}
