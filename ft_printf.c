/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayeema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:05:00 by chayeema          #+#    #+#             */
/*   Updated: 2024/01/10 18:29:24 by chayeema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(va_list args, char str, int *len)
{
	if (str == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (str == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (str == 'p')
		ft_pointer(va_arg(args, unsigned long), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (str == 'u')
		ft_unsigned(va_arg(args, unsigned int), len);
	else if (str == 'x')
		ft_hex_mini(va_arg(args, unsigned int), len);
	else if (str == 'X')
		ft_hex(va_arg(args, unsigned int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &len);
		else if (*str == '%' && *(str + 1) != '%')
		{
			ft_check(args, *(str + 1), &len);
			str++;
		}
		else if (*str == '%' && *(str + 1) == '%' && str++)
			ft_putchar('%', &len);
		str++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int		len;
	char	*str = "42";

	len = printf("Hello %s\n", str);
	printf("%d\n", len);
	len = ft_printf("Hello %s\n", str);
	printf("%d\n", len);

	len = printf("Hello %s\n", "Chi");
	printf("%d\n", len);
	len = ft_printf("Hello %s\n", "Chi");
	printf("%d\n", len);

	len = printf("decimal %d\n", 104210);
	printf("%d\n", len);
	len = ft_printf("decimal %d\n", 104210);
	printf("%d\n", len);

	len = printf("decimal %d\n", -104210);
	printf("%d\n", len);
	len = ft_printf("decimal %d\n", -104210);
	printf("%d\n", len);

	len = printf("Hello %x\n", 255);
	printf("%d\n", len);
	len = ft_printf("Hello %x\n", 255);
	printf("%d\n", len);

	len = printf("Hello %x\n", -42);
	printf("%d\n", len);
	len = ft_printf("Hello %x\n", -42);
	printf("%d\n", len);

	len = printf("[printf] %%\n");
	printf("%d\n", len);
	len = ft_printf("[ft_printf] %%\n");
	printf("%d\n", len);

	len = printf("[printf] NULL %s NULL \n", NULL);
	printf("printf %d\n", len);
	len =ft_printf("[ft_printf] NULL %s NULL \n", NULL);
	printf("ft_printf %d\n", len);

	len = ft_printf("%p\n", "");
	printf("ft_printf %d\n",len);
	len =printf("%p\n", "");
	printf("printf %d\n",len);

	len = ft_printf("%x\n", "");
	printf("ft_printf %d\n",len);
	len =printf("%x\n", "");
	printf("printf %d\n",len);

	len = printf("%s\n", NULL);
	printf("printf %d\n",len);
	len = ft_printf("%s\n", NULL);
	printf("ft_printf %d\n",len);
}
*/
