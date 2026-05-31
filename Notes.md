23/mai - Filipa
Alterei o nome da main para o nome do nosso programa (push_swap).
iniciei a estrutura seguindo o video que partilhaste e coloquei varios comentarios com duvidas e notas para continuar a construcao.

25/mai
## funcao `normalize_index`:
- recebe o stack_a com os inteiros e o index inicializado em _-1_.
- normaliza atualizando o node->index (com funcao static get_min que identifica o valor minimo)
verifica se esta ordenado com o disorder_metric
**RETORNA: `Disorder_metric`**
    - Low disorder: if *disorder < 0.2*, your chosen method must run in O(n2) time.
    - Medium√disorder: if *0.2 ≤ disorder < 0.5*, your chosen method must run in
    O(n n) time.
    - High disorder: if *disorder ≥ 0.5*, your chosen method must run in O(n log n)
    time.

comecei a criar a `pb`.

26/mai
## funcoes em /operations 
operations
|_`addtostacks_ops` -> operacoes que adicionam nodes to stacks
    |_`stack_addtop` -> adds node to top of a stack
|_`pushpop_ops` -> operacoes de push e pop
    |_`pb` e `pa` -> push node to a/b
    |_`pop_stack `-> takes first node from stack
|_`rotatestacks_ops` -> operacoes de rotacao da stack
    |_`ra`, `rb` e `rr` -> rotate a, rotate b e rotate a and b at the same time
|_`revrotatestacks_ops` -> opercaoes de rotacao invertida da stack
    |_`rra`, `rrb` e `rrr` -> reverse rotate a, b, a and b at the same time
o caller destas funcoes (os algoritmos), devem fazer write da respectiva operacao (pb, pa, ra, etc.)

27/mai
## funcoes de inicializacao de stacks
src
|_`initialize_stacks`
    |_`stack_clear` -> frees the memory of the nodes and the stack. It's called when there's an error reating the node
    |_`stack_addtop` -> adds the node to the top of the stack
    |_`create_node` -> created the node with value equal to the given number, initializes index and postion to *-1*, and *next* and *prev* to *NULL*
    |_`stack_init` -> initializes a stack and creates a node for each number in the array. initializes the stack's *head* and *tail* to *NULL*, so that we can create an empty `stack b`.

29/mai
## Flags
**A ideia central**
Em vez de teres as stacks e os flags separados e passares tudo à parte, crias uma struct "mãe" que contém tudo:
```
typedef struct s_data
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    t_flags     *flags;
}   t_data;
```

**Porque resolve o problema?**
Agora as tuas funções de operações, em vez de receberem isto:
```
void    pb(t_stack *a, t_stack *b, t_flags *flags);  // 3 params, e ainda falta mais
```
Recebem só isto:
```
void    pb(t_data *data);  // 1 param, tem acesso a tudo
```
E dentro da função acedes assim:
```
data->stack_a   // a stack a
data->stack_b   // a stack b
data->flags->has_bench  // se bench está ativo
```

**Tens mesmo de passar sempre — mas só UMA coisa**
Sim, continuas a passar o `t_data` para todo o lado. A diferença é que em vez de passares 3 ou 4 argumentos separados, passas sempre só 1 ponteiro — e isso nunca viola a norminette.

Finalizei o algoritmo `simple.c` - **Min extraction method**. Falta passar as flags.

## Algoritmo
Comecei a funcao `sort_upto3nbr.c` para fazer o sorting de quando os numeros sao menores ou igual a 3, pois nao e necessario rodar um algoritmo - seria ineficiente.

#31/mai
atualizei todas as operacoes e start program com o novo struct t_data.
comecei a desenvolver o sort 3 numbers (que nao precisa de chamar disorder nem algoritmos).
Encontrei um erro nas funcoes de operacoes (nao estao a atulizar o tail)
TO DO: rever funcoes de operacoes para validar que os nos e stacks sao atualizados (next, prev, head e tail).

### NAO ESQUECER:
- norminette
- substituir printf por ft_printf se usarmos
- fazer free cada vez que ha chamadas de funcoes que usam malloc
- mudar algumas funcoes para static