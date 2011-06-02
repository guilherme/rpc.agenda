#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

imprimeRegistro(reg)
registro reg;
{ 
  printf("======================================================");
  printf("Contato:\n ");
  printf("Nome: %s\n",reg.nome);
  printf("Email: %s\n",reg.email);
  printf("Telefone Residencial: %s\n",reg.telefone_residencial);
  printf("Telefone Celular: %s\n",reg.telefone_celular);
  printf("======================================================");
};

void
agenda_1(char *host)
{
  CLIENT *clnt;
  int  *result_1;
  char *inicializar_1_arg;
  int  *result_2;
  registro  insere_1_arg;
  int  *result_3;
  registro  remove_1_arg;
  registro  *result_4;
  char * busca_1_arg;
  int  *result_5;
  struct registro  altera_1_arg;
  int resultado;

#ifndef	DEBUG
  clnt = clnt_create (host, AGENDA, AGENDAVERS, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror (host);
    exit (1);
  }
#endif	/* DEBUG */

  result_1 = inicializar_1((void*)&inicializar_1_arg, clnt);
  if (result_1 == (int *) NULL) {
    clnt_perror (clnt, "call failed");
  }
  int opcao = 5;
  while(opcao != -1) {
    switch(opcao) {
    case 1:
      printf("Digite o nome do contato:\n");
      scanf("%s",insere_1_arg.nome);
      printf("Digite o email do contato:\n");
      scanf("%s",insere_1_arg.email);
      printf("Digite o telefone residencial do contato:\n");
      scanf("%s",insere_1_arg.telefone_residencial);
      printf("Digite o telefone celular do contato:\n");
      scanf("%s",insere_1_arg.telefone_celular);
      result_2 = insere_1(&insere_1_arg, clnt); 
      if(result_2 == (int *)NULL) {
          clnt_perror (clnt, "call failed");
      } else {
        resultado = *result_2;
        switch(resultado)  {
          case 0:
            printf("Erro ao inserir contato\n");
	    break;
          case 1:
            printf("Contato inserido com sucesso!\n");
	    break;
          case 2:
            printf("[SERVIDOR] Erro ao conectar ao banco de dados!\n");
	    break;
        };
      }
      opcao = 5;
      break;
    case 2:
      printf("Digite o email do contato:\n");
      scanf("%s",remove_1_arg.email);
      result_3 = remove_1(&remove_1_arg, clnt);
      if(result_3 == (int *)NULL) {
          clnt_perror (clnt, "call failed");
      } else {
        resultado = *result_3;
        switch(resultado)  {
          case -1:
            printf("Contato inexistente!\n");
	    break;
          case 0:
            printf("Erro ao remover contato\n");
	    break;
          case 1:
            printf("Contato removido com sucesso!\n");
	    break;
        };
      }
      opcao = 5;
      break;
    case 3:
      printf("Digite o email do contato:\n");
      scanf("%s",busca_1_arg);
      result_4 = busca_1(&busca_1_arg, clnt);
      if (result_4 == (registro *) NULL) {
        clnt_perror (clnt, "call failed");
      } else {
        imprimeRegistro(*result_4);
      }
      opcao = 5;
      break;
    case 4:
      printf("Digite o email do contato(sera utilizado como referencia):\n");
      scanf("%s",altera_1_arg.email);
      printf("Digite o nome do contato:\n");
      scanf("%s",altera_1_arg.nome);
      printf("Digite o telefone residencial do contato:\n");
      scanf("%s",altera_1_arg.telefone_residencial);
      printf("Digite o telefone celular do contato:\n");
      scanf("%s",altera_1_arg.telefone_celular);
      result_5 = altera_1(&altera_1_arg, clnt);
      if(result_5 == (int *)NULL) {
          clnt_perror (clnt, "call failed");
      } else {
        resultado = *result_5;
        switch(resultado)  {
          case -1:
            printf("Contato inexistente!\n");
	    break;
          case 0:
            printf("Erro ao alterar contato\n");
	    break;
          case 1:
            printf("Contato alterar com sucesso!\n");
	    break;
        };
      }
      opcao = 5;
      break;
    case 5:
      printf("Menu\n");
      printf(" 1 - Insere registro\n");
      printf(" 2 - Remove registro\n");
      printf(" 3 - Busca registro\n");
      printf(" 4 - Altera Registro\n");
      printf(" 5 - Menu\n");
      printf(" -1 - Sair\n");
      scanf("%d",&opcao);
      break;
    default:
      opcao = 5;
      break;
    }
  }
#ifndef	DEBUG
  clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
  char *host;

  if (argc < 2) {
    printf ("usage: %s server_host\n", argv[0]);
    exit (1);
  }
  host = argv[1];
  agenda_1 (host);
  exit (0);
}
