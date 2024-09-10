/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_double_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:23:20 by jquil             #+#    #+#             */
/*   Updated: 2023/10/31 10:09:29 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_not_quoted_2(char *str, int x, int end)
{
	int	p1;
	int	p2;

	if (str[x] == 39)
	{
		p1 = x;
		while (str[++x] != 39)
			;
		p2 = x;
		if (end > p1 && end < p2)
			return (0);
	}
	if (str[x] == 34)
	{
		p1 = x;
		while (str[++x] != 34)
			;
		p2 = x;
		if (end > p1 && end < p2)
			return (0);
	}
	return (1);
}

int	pipe_not_quoted(char *str, int end)
{
	int	x;

	x = -1;
	while (str[++x])
	{
		if (pipe_not_quoted_2(str, x, end) == 0)
			return (0);
	}
	return (1);
}

int	expand_not_quoted(char *str, int dollar)
{
	int	x;
	int	p1;
	int	p2;

	x = -1;
	dollar = ft_need_expand(str);
	while (str[++x])
	{
		if (str[x] == 39)
		{
			p1 = x;
			while (str[++x] && str[x] != 39)
				;
			if (!str[x])
				return (0);
			p2 = x;
			if (dollar > p1 && dollar < p2)
				return (0);
		}
	}
	return (1);
}

bool	ft_arg_empty(char *arg)
{
	int	x;

	x = -1;
	while (arg[++x])
	{
		if (arg[x] != 34 && arg[x] != 39 && arg[x] != 32)
			return (0);
	}
	return (1);
}

char	**ft_split_quote(t_shell *shell, char *arg)
{
	int		x;
	char	**tab;

	tab = NULL;
	x = -1;
	if (ft_arg_empty(arg) == 1)
		return (free(arg), NULL);
	while (arg[++x])
	{
		if (arg[x] == 39 && ft_next_quote(arg, 39, x) == 1)
		{
			while (arg[++x] && arg[x] != 39)
				;
		}
		else if (arg[x] == 34 && ft_next_quote(arg, 34, x) == 1)
		{
			while (arg[++x] && arg[x] != 34)
				;
		}
		else if ((arg[x] == 34 && ft_next_quote(arg, 34, x) == 0)
			|| (arg[x] == 39 && ft_next_quote(arg, 39, x) == 0))
			return (NULL);
	}
	return (ft_split_str(shell, arg, tab));
}
