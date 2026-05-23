#include "push_swap.h"

// stack init : inicializa uma stack com inteiros recebidos da main/push_swap

void	stack_init(t_stack **a, char **argv)
{
	// a e um ponteiro para ponteiro para poder alterar para onde aponta
	int		nbr;
	size_t	i;
	//converter strings para numeros
	while (*argv)
	{
		nbr = ft_atoi(argv[i]);
		// check se nao e menor/maior que INTMIN/MAX - validar retorno de atoi
		//check de repeticao
		// check se e numero - validar retorno de atoi
			//chamar funcao Erro que printa Error.
			// da free de tudo que tenha memoria (funcao error_free): atoi, stack
		//se nao der erro -> add_lstnew to stack a (validar que lstaddback valida se a e null e adiciona atras)
		i++;
	}
	//free dos argvs assim que criarmos os int e os colocamos na stack
}