/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:56:57 by flweynan          #+#    #+#             */
/*   Updated: 2023/02/16 13:10:00 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "cspdiuxX%";
	while (flags[i])
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_convert(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	if (c == 's')
		ft_putstr(va_arg(args, void *), count);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), SIGNED, DECIMAL, count);
	if (c == 'p')
		ft_printmem(va_arg(args, void *), count);
	if (c == 'u')
		ft_putnbr_base(va_arg(args, int), UNSIGNED, DECIMAL, count);
	if (c == 'x')
		ft_putnbr_base(va_arg(args, int), UNSIGNED, LOWER_HEXADECIMAL, count);
	if (c == 'X')
		ft_putnbr_base(va_arg(args, int), UNSIGNED, UPPER_HEXADECIMAL, count);
	if (c == '%')
		ft_putchar('%', count);
}
