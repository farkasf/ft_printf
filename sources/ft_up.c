/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:27:50 by ffarkas           #+#    #+#             */
/*   Updated: 2023/02/13 22:07:32 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int num)
{
	char	*str;
	int	len;

	len = ft_numlen(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	str[len] = '\0';
	while (num)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len --;
	}
	return (str);
}

int	ft_print_u(va_list *args)
{
	char	*str;
	int		count;
	unsigned int		num;

	num = va_arg(*args, unsigned int);
	count = 0;
	if (num == 0)
	{
		fd_putchar_fd("0", 1);
		return (1);
	}
	else
	{
		str = ft_uitoa(num);
		ft_putstr_fd(str, 1);
		count = ft_strlen(str);
		free (str);
	}
	return (count);
}

int	ft_ptrlen(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

void	ft_putptr(unsigned long long int ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_p(va_list *args)
{
	unsigned long long int	ptr;
	int	count;

	ptr = va_arg(*args, unsigned long long int);
	ft_putstr_fd("0x", 1);
	count = 2;
	if (ptr == 0)
	{
		ft_putchar_fd("0", 1);
		return (3);
	}
	else
	{
		ft_putptr(ptr);
		count += ft_ptrlen(ptr);
	}
	return (count);
}