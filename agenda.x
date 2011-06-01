struct registro {
  char nome[200];
  char email[200];
  char telefone_residencial[16];
  char telefone_celular[16];
};

program AGENDA{  /* nome do programa remoto */
  version AGENDAVERS{  
    int INICIALIZAR(void) = 1; 
    int INSERE(registro) = 2;
    int REMOVE(registro) = 3; 
    registro BUSCA(string) = 4; 
    int ALTERA(struct registro) = 5; 
  } = 1; 
} = 0x30090949; 

