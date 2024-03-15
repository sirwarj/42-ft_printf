/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:25:59 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 20:54:12 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *str, ...);

void	ft_flags_init(t_flags *flags);
void	ft_flag_left(t_flags *flags);
void	ft_flag_digit(char c, t_flags *flags);
void	ft_flag_width(va_list *args, t_flags *flags);
int		ft_flag_precision(const char *str, int pos,
			va_list *args, t_flags *flags);
int		ft_isflag(int c);
int		ft_isspec(int c);
int		ft_istype(int c);
int		ft_pad_width(int width, int size, int zero);

int		ft_putchar(int c);
int		ft_print_char(int c, t_flags flags);

int		ft_putstr(const char *str);
int		ft_print_str(const char *str, t_flags *flags);

int		ft_print_ptr(unsigned long n, t_flags *flags);

char	*ft_utoa(unsigned int num);
char	*ft_xtoa(unsigned long num, const char format);
char	*ft_ltoa(long num);

#endif
