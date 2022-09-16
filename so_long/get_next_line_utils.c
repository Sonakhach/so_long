/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:48:50 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 10:36:41 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char	*s1)
{
	char	*new;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	new = (char *)malloc((i + 1) * sizeof(*s1));
	if (new == NULL)
		return (0);
	else
	{
		if (!s1 || !new)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] && s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] && s2)
		ptr[i++] = s2[j++];
	if (s1 != NULL)
		free(s1);
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strchr(char	*s, int c)
{
	int		i;
	char	l;

	i = 0;
	l = c;
	while (s[i] && s[i] != l)
		i++;
	if (s[i] == l)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s || !*s)
		return (0);
	l = ft_strlen(s);
	if (l < start || len == 0)
		i = 0;
	else if (len <= l - start)
		i = len;
	else
		i = l - start;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	j = 0;
	while (s[start] && j < i)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}
