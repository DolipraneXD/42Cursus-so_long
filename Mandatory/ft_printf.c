/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:52:50 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/07 18:08:33 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	if (str == NULL)
	{
		return (count = write(1, "(null)", 6));
	}
	i = 0;
	count = 0;
	while (str[i])
	{
		count += write (1, &str[i], 1);
		i++;
	}
	return (count);
}

int	formatchecker(va_list args, const char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (str[i] == 'u')
		count = ft_putnbr_un(va_arg(args, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count = ft_printhex(va_arg(args, unsigned int), str[i]);
	else if (str[i] == 'p')
		count = ft_printpointer(va_arg(args, void *));
	else if (str[i] == '%')
		count = ft_putchar('%');
	else if (str[i])
		count = ft_putchar(str[i]);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start (args, str);
	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += formatchecker(args, str, i);
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		if (str[i])
			i++;
	}
	va_end (args);
	return (count);
}
