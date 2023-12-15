/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:27:20 by atudor            #+#    #+#             */
/*   Updated: 2023/10/22 17:45:11 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../includes/ft_push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = malloc (sizeof(char) * ((ft_strlen(s1) + 1) + (ft_strlen(s2))));
	if (!res)
		return (true_free(&s1));
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char		a;
	const char	*x;
	int			i;

	a = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
		{
			x = &s[i];
			return ((char *)x);
		}
		i++;
	}
	if (a == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*sub;

	if (!s || len == 0)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (start >= size)
		return (NULL);
	else if (size - start < len)
		sub = malloc((size - start + 1) * (sizeof(char)));
	else
		sub = malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	len += start;
	while (s[start] && start < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
