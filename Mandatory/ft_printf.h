/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:36:54 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/23 09:35:01 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libc.h>
/** part 1 **/
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_printhex(unsigned int n, char c);
int		ft_printhexp(size_t n);
int		ft_printpointer(void *ptr);
int		ft_putnbr_un(unsigned int n);

#endif