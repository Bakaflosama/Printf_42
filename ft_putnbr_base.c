/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:32:00 by flweynan          #+#    #+#             */
/*   Updated: 2023/02/16 13:11:03 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_base(int nbr, char *base, int *count)
{
	write(1, &base[nbr], 1);
	*count += 1;
}

void	ft_putnbr_base(int n, int sign, char *base, int *count)
{
	unsigned int	size;
	unsigned int	un_nbr;

	un_nbr = n;
	size = ft_strlen(base);
	if (sign && n < 0)
	{
		un_nbr = -n;
		ft_putchar('-', count);
	}
	if (un_nbr > size - 1)
		ft_putnbr_base((un_nbr / size), sign, base, count);
	ft_putchar_base((un_nbr % size), base, count);
}
