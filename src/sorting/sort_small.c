#include "../push_swap.h"
static void  sort_three_v2(t_data *data)
{
    t_node *node1;
    t_node *node2;
    
    node1 = data->stack_a->head;
    node2 = node1->next;

    if (node2->value > node2->next->value)
    {
        ra(data);
        sa(data);
    }
    else
    {
        if (node1->value > node2->next->value)
            ra(data);
        else
            sa(data);
    }
}

static void  sort_three(t_data *data)
{
    t_node *node1;
    t_node *node2;
    
    node1 = data->stack_a->head;
    node2 = node1->next;
    if (node1->value < node2->value)
    {
        if (node2->value < node2->next->value)
            return ;
        if (node1->value < node2->next->value)
        {
            rra(data);
            sa(data);
        }
        else   
            rra(data);
    }
    else
        sort_three_v2(data);
}

void    sort_small(t_data *data)
{
    t_node *node1;

    node1 = data->stack_a->head;
    if (!data->stack_a || data->stack_a->size <= 1)
        return ;
    if (data->stack_a->size == 2)
    {
        if (node1->value > node1->next->value)
            sa(data);
        return ;
    }
    if (data->stack_a->size == 3)
        sort_three(data);
}
/* int main ()
{
    t_data data;
    
//     //nodes
//     t_node *node1 = malloc(sizeof(t_node));
// 	t_node *node2 = malloc(sizeof(t_node));
// 	t_node *node3 = malloc(sizeof(t_node));
    
    ft_bzero(&data, sizeof(t_data));
    data.flags.has_bench = 1;

    //nodes value
    node1->value = 0;
    node2->value = 1;
    node3->value = 2;

//     //nodes structure
//     node1->prev = NULL;
//     node1->next = node2;
//     node2->prev = node1;
//     node2->next = node3;
//     node3->prev = node2;
//     node3->next = NULL;

//     //init stack a
//     data.stack_a = malloc(sizeof(t_stack));
//     data.stack_a->head = node1;
//     data.stack_a->tail = node3;
//     data.stack_a->size = 3;

//     printf("a size= %zu\n", data.stack_a->size);
//     printf("BEFORE\n");
//     printf("a head= %d\n", data.stack_a->head->value);
//     printf("a tail= %d\n", data.stack_a->tail->value);

    sort_small(&data);
    printf("\nAFTER\n");
    printf("a head= %d\n", data.stack_a->head->value);
    printf("a tail= %d\n", data.stack_a->tail->value);

    // so para size==3:
    // printf("\n%d -> %d -> %d\n", data.stack_a->head->value, data.stack_a->head->next->value, data.stack_a->head->next->next->value);
    
    //teste de soma de operacoes no bench
    printf("sa: %d | ra: %d | rra: %d\n", data.bench.sa, data.bench.ra, data.bench.rra);
    
    //free
    free(data.stack_a);
    free(node1);
    free(node2);
    free(node3);
} */