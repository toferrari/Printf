/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:37:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/15 15:54:05 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

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

int			ft_printf(char *format, ...);
void		ft_init_struct(t_print *s_ptf);
int			ft_parse_flag(char **format, va_list *arg, char **str);
int			ft_flag_d(t_print ptf, int nb, char **str);
void		ft_strputnchr(char **str, char c, int n);
int			ft_call_arg(va_list *arg, char **str, t_print ptf);
int			ft_convert_signe(char **str, t_print ptf, int nb);
int			ft_flag_lld(t_print ptf, int64_t nb, char **str);
int			ft_flag_u(t_print ptf, unsigned int nb, char **str);
int			ft_flag_llu(t_print ptf, uint64_t nb, char **str);
int			ft_flag_pourcent(t_print ptf, char **str);
int			ft_flag_octal(t_print ptf, unsigned int nb, char **str);
int			ft_flag_hexa(t_print ptf, unsigned int nb, char **str);
int			ft_flag_str(t_print ptf, char *src, char **str);
int			ft_flag_chr(t_print ptf, char *c, char **str);
int			ft_flag_llhexa(t_print ptf, uint64_t nb, char **str);
int			ft_flag_hd(t_print ptf, int nb, char **str);

#endif
