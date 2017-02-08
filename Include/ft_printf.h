/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:37:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/08 16:55:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct	s_struct
{
	int			bool_acc;
	int			accuracy;
	int			htag;
	int			plus;
	int			moins;
	int			zero;
	int			width;
	int			h;
	int			l;
	int			L;
	int			space;
	int			z;
	int			j;
	char		c;

}				t_print;

void		ft_init_struct(t_print *s_ptf);
int			ft_parse_flag(char **format, va_list *arg, char **str);
int			ft_flag_d(t_print ptf, int nb, char **str);
void		ft_strputnchr(char **str, char c, int n);


#endif
