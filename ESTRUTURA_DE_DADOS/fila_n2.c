/*
 +-----------------------------------------------------------+
 | Programador...: Kleber de Andrade Reis                    |
 | Descrição.....: Programa da lista de exercicio            |
 | Professora....: Simone                                    | 
 | Arquivo.......: fila_n2.c                                 |
 +-----------------------------------------------------------+

Lista Simplesmente Encadeada

	Desenvolva um programa, implementando as seguintes operações em filas. (cria, insere, exclui, vazia, imprime, primeiro, libera).
Sendo:
Cria: cria uma nova fila vazia.
Insere: inclui um elemento da fila.
Exclui: exclui um elemento da fila.
Vazia: retorna se a fila está vazia ou não.
Imprime: Imprime no vídeo os elementos da fila.
Primeiro: retorna o primeiro elemento da fila.

Libera: libera a memória alocada pela fila



	Desenvolva uma rotina para incluir dois elementos na fila (insere2).

	Desenvolva uma rotina para excluir n elementos da fila (excluin).
*/

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(x) ((x *) malloc (sizeof(x)))


//declaração da estrutura
struct no{
   int n1,n2,n3,n4;
   char aluno[30];
   struct no *proximo;
         };

typedef struct no no_t;
no_t *novo;


//declaração das funções
no_t *cria(no_t *lista);
no_t *insini(no_t *lista);
no_t *insfim(no_t *lista);
no_t *insere2(no_t *lista);
no_t *retira(no_t *lista);
no_t *retiran(no_t *lista, int k);
int imprime(no_t *lista);
int vazia(no_t *lista);
int primeiro(no_t *lista);
no_t *libera(no_t *lista);


int main(void)
{
   int op,k,r,m;
   no_t *lista;
   for (;;)
   {
      system("clear");
      printf("\n0 - Cria uma lista");
      printf("\n1 - Inclui um elemento na fila");
      printf("\n2 - Inclui dois elemento na fila");
      printf("\n3 - Exclui um elemento da fila");
      printf("\n4 - Exclui n elemento da fila");
      printf("\n5 - Verifica se a fila esta vazia");
      printf("\n6 - Imprime os elementos da fila");
      printf("\n7 - Imprime o primeiro elemento da fila");
      printf("\n8 - Libera memoria");
      printf("\n9 - Sair");
      printf("\n\nSua opcao: \n");
      scanf("%d",&op);
      switch(op){
         case 0 : 
	    lista=cria(lista);
            break;
         case 1 : 
            getchar();
            if(lista==NULL)
               lista=insini(lista);
            else
               lista=insfim(lista);
            break; 
         case 2 : 
            getchar();
	    lista=insere2(lista);
            break;                          
         case 3 : 
            lista=retira(lista);
            break;
         case 4 : 
            system("clear");
            printf("Digite a quantidade a ser excluida\n");
            scanf("%d",&k);
            lista=retiran(lista,k);
            break;
         case 5 :
            vazia(lista);
            break;
         case 6 : 
            imprime(lista);
            break;
         case 7 :
            primeiro(lista);
            break;
         case 8 : 
            lista=libera(lista);
            break;
         case 9 : 
            exit(0);
         default: 
            system("clear");
            printf("Opção Errada");
            scanf("%d",&k);
      }
   }    
   return 0;            
}


no_t *cria(no_t *lista){
   system("clear");
   lista = MALLOC(no_t);
   lista=0;
   printf("Lista criada com sucesso!!!\n");
   sleep(3);
   return lista;
};


no_t *retiran(no_t *lista, int k)
{
   int i=0;
   no_t *p;
   p=lista;
   
   while(i<k)
   {
      if(lista!=NULL)
      {
         lista=lista->proximo;
         free(p);
	 p=lista;
      }
      else
         return NULL;
      i++;        
   }
   return lista;
};


no_t *retira(no_t *lista)
{
   no_t *p;
   p=lista;
   if(lista!=NULL)
   {
      lista=lista->proximo;
      free(p);
      return lista;
   }
   return NULL;
};


no_t *libera(no_t *lista)
{
   no_t *p;
   p=lista;
   if(lista!=NULL)
   {
      while(p!=NULL)
      {
         p=lista->proximo;
         free(lista);
         lista=p;
      }
   }
    return NULL;
};


no_t *insini(no_t *lista)
{
   int n1,n2,n3,n4;
   char al[30];

   printf("Digite o nome do aluno\n");
   gets(al);
   printf("N1: ");
   scanf("%d",&n1);
   printf("N2: ");
   scanf("%d",&n2);
   printf("N3: ");
   scanf("%d",&n3);
   printf("N4: ");
   scanf("%d",&n4);

   novo = MALLOC(no_t);
   novo->proximo = lista; 
   sprintf(novo->aluno,"%s",al);
   novo->n1 = n1;
   novo->n2 = n2;
   novo->n3 = n3;
   novo->n4 = n4;  
   return novo;
};

 
no_t *insfim(no_t *lista)
{
   int n1,n2,n3,n4;
   no_t *aux;
   char al[30];
   aux=lista;

   printf("Digite o nome do aluno\n");
   gets(al);
   printf("N1: ");
   scanf("%d",&n1);
   printf("N2: ");
   scanf("%d",&n2);
   printf("N3: ");
   scanf("%d",&n3);
   printf("N4: ");
   scanf("%d",&n4);

   novo = MALLOC(no_t);
   while(aux->proximo!=NULL)
   {
      aux=aux->proximo;
   }
   novo->proximo = NULL;
   sprintf(novo->aluno,"%s",al);
   novo->n1 = n1;
   novo->n2 = n2;
   novo->n3 = n3;
   novo->n4 = n4;
   aux->proximo=novo;
   return lista;
};


no_t *insere2(no_t *lista)
{
   int n1,n2,n3,n4,i=0;
   char al[30];
   no_t *aux;

   aux=lista; 
   while(i<2)
   {
      printf("Digite o nome do aluno\n");
      gets(al);
      printf("N1: ");
      scanf("%d",&n1);
      printf("N2: ");
      scanf("%d",&n2);
      printf("N3: ");
      scanf("%d",&n3);
      printf("N4: ");
      scanf("%d",&n4);

      novo = MALLOC(no_t);

      novo->proximo = NULL; 
      sprintf(novo->aluno,"%s",al);
      novo->n1 = n1;
      novo->n2 = n2;
      novo->n3 = n3;
      novo->n4 = n4;
      if(aux==NULL)
      {
         aux=novo;
         aux->proximo=NULL;
         lista=aux;
      }
      else
      {
         while(aux->proximo!=NULL)
         {
            aux=aux->proximo;
         }
         aux->proximo=novo;
      }
      i++;
      getchar();
   }
   return lista;
};


int imprime(no_t *lista)
{
   no_t *p;
   int k,i=0;
   system("clear");
   if (lista==NULL)
   {
      system("clear");
      printf("Lista Vazia");
      scanf("%d",&k);
      return 0;
   }
   p = lista;
   do{
      printf("\nAluno: %s",p->aluno);
      printf("\nN1: %d",p->n1);
      printf("\nN2: %d",p->n2);
      printf("\nN3: %d",p->n3);
      printf("\nN4: %d",p->n4);
      printf("\n");
      p = p->proximo;
      i++;
   }while (p!=NULL);
   printf("\n\nTEM %d ITENS NA LISTA",i);  
   scanf("%d",&k);
   return 0; 
};


int vazia(no_t *lista)
{
   system("clear");
   no_t *p;
   p=lista;
   int i=0;
   while(p!=NULL)
   {
      p=p->proximo;
      i++;
   }
   if(i==0)
      printf("A lista esta vazia!!!\n");
   else
      printf("\n\nTEM %d ITENS NA LISTA",i);
   sleep(3);
   return i;
};

int primeiro(no_t *lista)
{
   no_t *p;
   int k;
   system("clear");
   if (lista==NULL)
   {
      system("clear");
      printf("Lista Vazia");
      scanf("%d",&k);
      return 0;
   }
   p = lista;
   printf("\nAluno: %s",p->aluno);
   printf("\nN1: %d",p->n1);
   printf("\nN2: %d",p->n2);
   printf("\nN3: %d",p->n3);
   printf("\nN4: %d",p->n4);
   printf("\n"); 
   scanf("%d",&k);
   return 0; 
};
