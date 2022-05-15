/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:27:33 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/15 19:40:22 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putuint(unsigned int nb)
{
	char	c;

	if (nb > 9)
	{
		ft_putuint(nb / 10);
	}
	nb = nb % 10;
	c = nb + '0';
	ft_putchar_fd(c, 1);
}

static void	ft_puthex(unsigned int nb, char c)
{
	char	*index_1;
	char	*index_2;

	index_1 = "0123456789abcdef";
	index_2 = "0123456789ABCDEF";
	if (nb > 16)
	{
		ft_puthex(nb / 16, c);
	}
	nb = nb % 16;
	if (c == 'x')
		ft_putchar_fd(index_1[nb], 1);
	else
		ft_putchar_fd(index_2[nb], 1);
}

static void	ft_putaddr(unsigned long nb)
{
	char	*index;

	index = "0123456789abcdef";
	if (nb > 16)
	{
		ft_putaddr(nb / 16);
	}
	nb = nb % 16;
	ft_putchar_fd(index[nb], 1);
}

void	ft_format(const char *format, va_list args)
{

	if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format == 'u')
		ft_putuint(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(args, unsigned int), *format);
	else if (*format == 'p')
	{
		if (va_arg(args, unsigned long) == 0)
			ft_putstr_fd(PTR_NULL, 1);
		else
		{
			ft_putstr_fd("0x", 1);
			ft_putaddr(va_arg(args, unsigned long));
		}
	}
	else if (*format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == '%')
		ft_putchar_fd('%', 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
}
