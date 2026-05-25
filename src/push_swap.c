#include "push_swap.h"

// Funcao main que recebe os argumentos do utlilzador
/*Cria a stack com os argumentos
validar se tem erros
validar se esta ordenado
chamar argumentos
dar free da memoria */

int main (int argc, char ** argv)
{
    t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
    //validar se chamada tem argumentos e se str nao e nula
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return(0);

    // split da string em strings individuais com os numeros (ainda em char *)
    else // esta condicao nao e valida para nos porque quando temos flags argc > 2; 
        argv = ft_split(argv[1], ' '); //-> como funciona para argc > 2? loop while (argv[i]) > ft_split?
    // identificar flags (antes da stack init) -- como definimos quando termina a string de numeros? Temos de garantir que o programa funciona para ./push_swap "1 2" e ./push_swap 1 2 ???
    // stack_init com array de char * argv

    // !! Ainda falta o disorder e a escolha do algoritmo com base no disorder!!

}