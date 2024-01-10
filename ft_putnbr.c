/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayeema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:43:42 by chayeema          #+#    #+#             */
/*   Updated: 2024/01/10 18:30:26 by chayeema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long nb, int *len)
{
	ft_putstr("0x", len);
	ft_hex_mini(nb, len);
}

void	ft_putnbr(int nb, int *len)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		n %= 10;
	}
	if (n < 10)
		ft_putchar((n + '0'), len);
}

void	ft_unsigned(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_unsigned(nb / 10, len);
		nb %= 10;
	}
	ft_putchar((nb + '0'), len);
}

void	ft_hex_mini(unsigned long nb, int *len)
{
	if (nb >= 16)
		ft_hex_mini(nb / 16, len);
	ft_putchar("0123456789abcdef"[nb % 16], len);
}

void	ft_hex(unsigned int nb, int *len)
{
	if (nb >= 16)
		ft_hex(nb / 16, len);
	ft_putchar("0123456789ABCDEF"[nb % 16], len);
}
