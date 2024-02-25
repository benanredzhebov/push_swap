#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int cost;
	struct s_node *next;
} t_node;

t_node	*choose(t_node **b)
{
	int		min;
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *b;
	tmp1 = tmp;
	min = tmp->cost;
	while (tmp)
	{
		if (tmp->cost < min)
		{
			min = tmp->cost;
			tmp1 = tmp;
		}
		tmp = tmp->next;
	}
	return (tmp1);
}

void print_cost(t_node *node) {
	printf("Chosen node cost: %d\n", node->cost);
}

// ... Your choose function here ...

int main() {
	t_node *a = malloc(sizeof(t_node));
	a->cost = 10;
	a->next = malloc(sizeof(t_node));
	a->next->cost = 1;
	a->next->next = malloc(sizeof(t_node));
	a->next->next->cost = 5;
	a->next->next->next = NULL;

	t_node *chosen = choose(&a);

	print_cost(chosen);

	// Free memory
	free(a->next->next);
	free(a->next);
	free(a);

	return 0;
}