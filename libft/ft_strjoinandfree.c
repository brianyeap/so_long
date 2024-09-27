/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinandfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:47:57 by brian             #+#    #+#             */
/*   Updated: 2024/09/23 00:35:32 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinandfree(char *s1, char *s2)
{
	char	*mem;
	int		i;
	int		j;
    
    if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	mem = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!mem)
		return (NULL);
	while (s1[i])
    
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		mem[i + j] = s2[j];
		j++;
	}
	mem[i + j] = '\0';
	free(s1);
	return (mem);
}