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

t_node	*ft_node_last(t_node *nodes)
{
	if (!nodes)
		return (NULL);
	while (nodes->next)
		nodes = nodes->next;
	return (nodes);
}

void	ft_node_add_back(t_node **nodes, t_node *new)
{
	t_node	*last;

	if (!nodes || !new)
		return ;
	if (!*nodes)
	{
		*nodes = new;
		return ;
	}
	last = ft_node_last(*nodes);
	last->next = new;
}

void	ft_node_add_front(t_node **nodes, t_node *new)
{
	if (nodes && new)
	{
		new->next = *nodes;
		*nodes = new;
	}
}

int	ft_node_size(t_node *nodes)
{
	int	count;

	count = 0;
	while (nodes)
	{
		nodes = nodes->next;
		count++;
	}
	return (count);
}
