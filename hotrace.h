/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 17:32:27 by grebett           #+#    #+#             */
/*   Updated: 2013/12/15 14:42:12 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

/*
** defines
*/
# define BUFF_SIZE 1024

/*
** includes
*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>

/*
** structures
*/
typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*key;
	char			*value;

}					t_btree;

/*
** prototypes
*/
t_btree		*btree_create_node(char *key, char *value);
void		btree_apply_infix(t_btree *root, void (*f)(void *));
void		fill_tree(t_btree *node, char *key, char *value);
char		*search_tree(t_btree *node, char *key);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strlen(const char *str);
void		ft_putendl(char *str);
void		ft_putstr(char *str);
char		*ft_strnew(size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

int			get_next_line(int const fd, char **line);

#endif	/* !HOTRACE_H */
