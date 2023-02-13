/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:20:10 by ffarkas           #+#    #+#             */
/*   Updated: 2023/02/13 21:26:19 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_get_param(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_print_c(args);
	else if (format == 's')
		length += ft_print_s(args);
	else if (format == 'p')
		length += ft_print_p(args);
	else if (format == 'd' || format == 'i')
		length += ft_print_di(args);
	else if (format == 'u')
		length += ft_print_u(args);
	else if (format == 'x' || format == 'X')
		length += ft_print_xX(args, format);
	else if (format == '%')
		length += ft_print_percent();
	return (length);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	char	*str;
	int		i;
	int		return_length;

	str = (char *)input;
	i = 0;
	return_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			return_length += ft_get_param(args, str[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			return_length++;
			i++;
		}
	}
	va_end(args);
	return (return_length);
}
