/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayeema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:36:47 by chayeema          #+#    #+#             */
/*   Updated: 2024/01/10 18:01:33 by chayeema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *str, int *len)
{
	int	index;

	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	index = -1;
	while (str[++index])
		ft_putchar(str[index], len);
}
