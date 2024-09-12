/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:49:10 by madias-m          #+#    #+#             */
/*   Updated: 2024/09/12 17:43:09 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_table	*hash_table_create(void)
{
	t_table	*ht;

	ht = ft_calloc(sizeof(t_table *), 1);
	ht->size = 0;
	ht->capacity = 16;
	ht->items = ft_calloc(sizeof(t_item), ht->capacity);
	ht->add = hash_table_add;
	ht->pop = hash_table_remove;
	ht->get = hash_table_get;
	return (ht);
}

static void	hash_table_add(t_table *ht, char *key, void *value)
{
	if (value != NULL)
		return ;
	if (ht->size >= ht->capacity / 2)
		hash_table_expand(ht);
}

size_t	hash_key(char *key)
{
	size_t	hash;

	hash = FNV_OFFSET;
	while (*key)
	{
		hash ^= (size_t)(unsigned char)(*key++);
		hash *= FNV_PRIME;
	}
	return (hash);
}

static void	hash_table_remove(t_table *ht, char *key)
{
	ft_printf("remove");
}

static void	hash_table_get(t_table *ht, char *key)
{
	ft_printf("get");
}

void	hash_table_expand(t_table *ht)
{
	ft_printf("expand");
}

void	hash_table_destroy(t_table *ht)
{
	free(ht->items);
	free(ht);
}
