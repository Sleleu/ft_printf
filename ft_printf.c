/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:12:10 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/15 19:44:39 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	len;
	va_list	args;
	
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(format++, args);
		}
		else
			len++;
		if (*format == '\0')
			break;
		ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

/*
int	main(void)
{

	char	*tab = "test";
	char	*vide = "";
	char	*null = NULL;
        printf("char %c int %d str %s uint %u hex %x pointeur %p\n", 'A', 456, "test", -123456, 154878, tab);
	ft_printf("char %c int %d str %s uint %u hex %x pointeur %p\n", 'A', 456, "test", -123456, 154878, tab);

	printf("test 2 : str vide %s\n", vide);
        ft_printf("test 2 : str vide %s\n", vide);
	ft_printf("%p\n", null);
	printf("%p\n", null);


	printf(" %c ", '0');
	ft_printf(" %c ", '0');
	return (0);
	
}*/
