/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:12:39 by moel-fat          #+#    #+#             */
/*   Updated: 2024/03/05 16:35:47 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	cc = (unsigned char)c;
	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = cc;
		i++;
	}
	return (b);
}
