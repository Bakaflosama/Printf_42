/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:50:37 by flweynan          #+#    #+#             */
/*   Updated: 2023/02/16 13:11:48 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int *count)
{
	*count += 1;
	write(1, &c, 1);
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
		ft_putstr("(null)", count);
	while (str && *str)
	{
		ft_putchar(*str, count);
		str++;
	}
}

void	ft_putadress(unsigned long adr, int *count)
{
	if (adr > 15)
		ft_putadress(adr / 16, count);
	ft_putchar_base(adr % 16, LOWER_HEXADECIMAL, count);
}

void	ft_printmem(void *args, int *count)
{
	unsigned long	adr;

	adr = (unsigned long) args;
	ft_putstr("0x", count);
	ft_putadress(adr, count);
}
