/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:37:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/01 17:45:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct	s_struct
{
	char		*flag;
	char		*len_flag;
	char		out_ampl_flag;
	int			bool_acc;
	int			accuracy;
	char		type_spec;
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

}				t_print;

int			ft_parse_flag(char **format, va_list *arg);

#endif
