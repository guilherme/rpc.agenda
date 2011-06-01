/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _AGENDA_H_RPCGEN
#define _AGENDA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct registro {
	char nome[200];
	char email[200];
	char telefone_residencial[16];
	char telefone_celular[16];
};
typedef struct registro registro;

#define AGENDA 0x30090949
#define AGENDAVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define INICIALIZAR 1
extern  int * inicializar_1(void *, CLIENT *);
extern  int * inicializar_1_svc(void *, struct svc_req *);
#define INSERE 2
extern  int * insere_1(registro *, CLIENT *);
extern  int * insere_1_svc(registro *, struct svc_req *);
#define REMOVE 3
extern  int * remove_1(registro *, CLIENT *);
extern  int * remove_1_svc(registro *, struct svc_req *);
#define BUSCA 4
extern  registro * busca_1(char **, CLIENT *);
extern  registro * busca_1_svc(char **, struct svc_req *);
#define ALTERA 5
extern  int * altera_1(struct registro *, CLIENT *);
extern  int * altera_1_svc(struct registro *, struct svc_req *);
extern int agenda_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INICIALIZAR 1
extern  int * inicializar_1();
extern  int * inicializar_1_svc();
#define INSERE 2
extern  int * insere_1();
extern  int * insere_1_svc();
#define REMOVE 3
extern  int * remove_1();
extern  int * remove_1_svc();
#define BUSCA 4
extern  registro * busca_1();
extern  registro * busca_1_svc();
#define ALTERA 5
extern  int * altera_1();
extern  int * altera_1_svc();
extern int agenda_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_registro (XDR *, registro*);

#else /* K&R C */
extern bool_t xdr_registro ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_AGENDA_H_RPCGEN */