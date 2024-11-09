#include "ft_printf.h"

t_node	*ft_node_new(char chr)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->chr = chr;
		new_node->next = NULL;
	}
	return (new_node);
}

t_node	*ft_node_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_node_add_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!node || !new)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	last = ft_node_last(*node);
	last->next = new;
}

void	ft_node_add_front(t_node **node, t_node *new)
{
	if (node && new)
	{
		new->next = *node;
		*node = new;
	}
}

int	ft_node_size(t_node *node)
{
	int	count;

	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}
