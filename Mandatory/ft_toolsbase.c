/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolsbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:57:10 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/08 12:20:19 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
	{
		count += ft_putchar(n + '0');
	}
	else if (n < 0)
	{
		if (n == -2147483648)
			count += write(1, "-2147483648", 11);
		else
		{
			count += ft_putchar('-');
			count += ft_putnbr(-n);
		}
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = n;
	if (n < 10)
		count += ft_putchar((n + '0'));
	else
	{
		count += ft_putnbr_un(n / 10);
		count += ft_putnbr_un(n % 10);
	}
	return (count);
}

int	ft_printhex(unsigned int n, char c)
{
	int		count;
	char	*bu;

	count = 0;
	if (c == 'X')
		bu = "0123456789ABCDEF";
	else
		bu = "0123456789abcdef";
	if (n < 16)
	{
		return (ft_putchar(bu[n]));
	}
	else
	{
		count += ft_printhex(n / 16, c);
		return (count += ft_printhex((n % 16), c));
	}
}

int	ft_printhexp(size_t n)
{
	int		count;
	char	*bu;

	count = 0;
	bu = "0123456789abcdef";
	if (n < 16)
	{
		return (ft_putchar(bu[n]));
	}
	else
	{
		count += ft_printhexp(n / 16);
		return (count += ft_printhexp((n % 16)));
	}
}

int	ft_printpointer(void *ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	return (count += ft_printhexp((size_t)ptr));
}
