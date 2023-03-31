#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}  t_list;
/*
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*aux;
	t_list	*prv;
	t_list	*begin;

	prv = *begin_list;
	begin = prv;
	if (prv == NULL)
		return;
	if (cmp(prv->data, data_ref) == 0)
	{
		*begin_list = prv->next;
		free(prv);
	}
	else
		aux = prv->next;
	while (aux)
	{
		if (cmp(aux->data, data_ref) == 0)
		{
			prv->next = aux->next;
			free(aux);
			return ;
		}
		prv = aux;
		aux = aux->next;
	}
}
*/
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*aux; // Recebe o nó que esta sendo analisado
	t_list	*prv; // Recebe o nó anterior ao que está sendo analisado
	t_list	*temp; // É uma variável auxiliar que é usada para ajudar a da free em algum nó compativel

	temp = NULL; // Define temp = NULL, por questão de segurança
	aux = *begin_list; // Recebe o primeiro nó da lista recebida
	prv = NULL; // Define prv como NULL porque sempre que esta função começa, aux é o primeiro elemento da lista, e prv
				// tem a função de guardar o nó anterior à aux, sendo assim como não há elemento anterior ao primeiro
				// prv = NULL; Ao longo do programa o valor prv é modficdado, contudo, sempre será o nó anterior à aux;
	while (aux)
	{
		if (cmp(aux->data, data_ref) == 0) // caso o nó analisado seja compativel
		{
			if (prv == NULL) // Caso o nó compativel seja o primeiro nó da lista
			{
				*begin_list = aux->next;
				free(aux);
				aux = *begin_list;
			}
			else // Caso o nó compativel não seja o primeiro nó da lista
			{
				temp = aux;
				aux = aux->next;
				free(temp);
				prv->next = aux;
			}
		}
		else // caso o nó analisado não seja compativel
		{
			prv = aux;
			aux = aux->next;
		}
	}
}

void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", cur->data);
		cur = cur->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, "String bb", strcmp);
	print_list(begin_list);
}
