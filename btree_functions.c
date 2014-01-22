/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 17:36:04 by grebett           #+#    #+#             */
/*   Updated: 2013/12/15 14:41:20 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_btree	*btree_create_node(char *key, char *value)
{
	t_btree		*node;

	node = (t_btree *) malloc(sizeof(t_btree));
	if (node != NULL)
	{
		node->key = ft_strdup(key);
		node->value = ft_strdup(value);
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}

void	fill_tree(t_btree *node, char *key, char *value)
{
	if (ft_strcmp(key, node->key) < 0)
	{
		if (node->left != NULL)
		{
			node = node->left;
			fill_tree(node, key, value);
		}
		else
			node->left = btree_create_node(key, value);
	}
	else if (ft_strcmp(key, node->key) > 0)
	{
		if (node->right != NULL)
		{
			node = node->right;
			fill_tree(node, key, value);
		}
		else
			node->right = btree_create_node(key, value);
	}
	else
	{
		free(node->value);
		node->value = ft_strdup(value);
	}
}

char	*search_tree(t_btree *node, char *key)
{
	char	*str;

	if (ft_strcmp(key, node->key) < 0)
	{
		if (node->left != NULL)
		{
			node = node->left;
			str = search_tree(node, key);
		}
		else
			return (NULL);
	}
	else if (ft_strcmp(key, node->key) > 0)
	{
		if (node->right != NULL)
		{
			node = node->right;
			str = search_tree(node, key);
		}
		else
			return (NULL);
	}
	else
		str = node->value;
	return (str);
}
