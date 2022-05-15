/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:09:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/15 19:40:56 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

# if defined (__APPLE__)
#	define PTR_NULL "0x0"
# elif __linux__
#	define PTR_NULL "(nil)"
# endif

void	ft_format(const char *format, va_list args);
int	ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
