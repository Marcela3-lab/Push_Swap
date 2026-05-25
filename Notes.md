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