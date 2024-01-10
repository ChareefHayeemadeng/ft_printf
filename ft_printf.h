/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayeema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:18:56 by chayeema          #+#    #+#             */
/*   Updated: 2024/01/10 18:28:38 by chayeema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *str, ...);
void		ft_putchar(char c, int *len);
void		ft_putstr(char *str, int *len);
void		ft_pointer(unsigned long nb, int *len);
void		ft_putnbr(int nb, int *len);
void		ft_unsigned(unsigned int nb, int *len);
void		ft_hex_mini(unsigned long nb, int *len);
void		ft_hex(unsigned int nb, int *len);

#endif
