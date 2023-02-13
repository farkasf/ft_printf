/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:58:59 by ffarkas           #+#    #+#             */
/*   Updated: 2023/02/13 17:36:15 by ffarkas          ###   ########.fr       */
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

#endif
