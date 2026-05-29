#include "../push_swap.h"

void    sort_smallnbrs(t_stack *a)
{
    if (!a || a->size < 2)
        return ;
    if (a->size == 2)
        sa(a);
    update_positions(a);
    else if (a->size == 3)
    {
        //sa, ra e rra
    }
}
