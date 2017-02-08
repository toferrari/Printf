/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:33:13 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/16 18:35:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrnbr(char *str, int nb)
{
	ft_putstr(str);
	ft_putchar(' ');
	ft_putnbr(nb);
	ft_putendl(" :");
}
