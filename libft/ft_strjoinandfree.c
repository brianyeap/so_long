/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinandfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryeap <bryeap@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:47:57 by brian             #+#    #+#             */
/*   Updated: 2024/09/27 21:44:20 by bryeap           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinandfree(char *s1, char *s2)
{
	char	*mem;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = malloc((len1 + len2 + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, len1);
	ft_memcpy(mem + len1, s2, len2 + 1);
	mem[len1 + len2] = '\0';
	free(s1);
	return (mem);
}
