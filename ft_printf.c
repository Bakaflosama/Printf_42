/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flweynan <flweynan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:03:49 by flweynan          #+#    #+#             */
/*   Updated: 2023/02/16 13:12:15 by flweynan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start (args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && check_flags(str[i + 1]))
			ft_convert(str[++i], args, &count);
		else if (str[i] == '%' && !check_flags(str[i + 1]))
			i++;
		else
			ft_putchar(str[i], &count);
	}
	va_end(args);
	return (count);
}
