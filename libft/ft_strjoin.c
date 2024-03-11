/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:32:27 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/14 14:04:54 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tlen;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tlen = ft_strlen(s1) + ft_strlen(s2) +1;
	s = (char *) malloc (tlen);
	if (s == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(s, s1, tlen);
	ft_strlcat(s + ft_strlen(s1), s2, tlen);
	return (s);
}
