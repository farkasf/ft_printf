/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:27:50 by ffarkas           #+#    #+#             */
/*   Updated: 2023/02/13 21:43:36 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
