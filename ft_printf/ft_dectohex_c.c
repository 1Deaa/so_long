/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:52:51 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/18 13:04:56 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dectohex_c(unsigned int num)
{
	int	counter;

	counter = 0;
	if (num >= 16)
	{
		counter += ft_dectohex_c(num / 16);
		ft_dectohex_c(num % 16);
		counter++;
	}
	else
	{
		if (num <= 9)
			counter += ft_putchar(num + '0');
		else
			counter += ft_putchar(num - 10 + 'A');
	}
	return (counter);
}
