23/mai - Filipa
Alterei o nome da main para o nome do nosso programa (push_swap).
iniciei a estrutura seguindo o video que partilhaste e coloquei varios comentarios com duvidas e notas para continuar a construcao.

25/mai
### funcao `normalize_index`:
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