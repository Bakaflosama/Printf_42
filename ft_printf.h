/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:19 by flweynan          #+#    #+#             */
/*   Updated: 2023/02/16 13:10:47 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# define DECIMAL "0123456789"
# define UPPER_HEXADECIMAL "0123456789ABCDEF"
# define LOWER_HEXADECIMAL "0123456789abcdef"
# define SIGNED 1
# define UNSIGNED 0

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *str, int *count);
int		check_flags(char c);
void	ft_convert(char c, va_list args, int *count);
void	ft_putnbr_base(int n, int sign, char *base, int *count);
void	ft_putchar_base(int nbr, char *base, int *count);
size_t	ft_strlen(char *str);
void	ft_printmem(void *args, int *count);
void	ft_putadress(unsigned long adr, int *count);

#endif
