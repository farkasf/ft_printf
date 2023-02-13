/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:58:59 by ffarkas           #+#    #+#             */
/*   Updated: 2023/02/13 21:21:32 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_get_param(va_list args, const char format);

int	ft_print_c(va_list *args);
int	ft_print_s(va_list *args);
int	ft_print_percent(void);
int	ft_print_di(va_list *args);
int	ft_puthex(unsigned int num, const char format);
int	ft_hexlen(unsigned int num);
int	ft_print_xX(va_list *args, const char format);

#endif
