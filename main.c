/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:45:18 by grebett           #+#    #+#             */
/*   Updated: 2013/12/15 20:45:47 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	print_result(t_btree **parent, char *key)
{
	char	*value;

	value = search_tree(*parent, key);
	if (value != NULL)
		ft_putendl(value);
	else
	{
		ft_putstr(key);
		ft_putstr(": ");
		ft_putendl("Not found.");
	}
}

t_btree	*set_pairs(t_btree *parent, char *key, char *value)
{
	static t_btree	*node;
	static int		flag = 0;

	if (flag++ == 0)
		node = btree_create_node(key, value);
	else
		fill_tree(parent, key, value);
	return (node);
}

int		main(void)
{
	t_btree		*parent;
	char		*key;
	char		*value;
	char		*str;

	while (1)
	{
		get_next_line(0, &str);
		if (str == NULL)
			return (1);
		key = ft_strdup(str);
		if (*str == '\0')
			break ;
		get_next_line(0, &str);
			value = ft_strdup(str);
		if (value != NULL)
			parent = set_pairs(parent, key, value);
		free(str);
	}
	while (get_next_line(0, &key) > 0)
		print_result(&parent, key);
	return (0);
}
