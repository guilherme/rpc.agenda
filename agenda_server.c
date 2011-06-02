#include "agenda.h"

int *
inicializar_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
insere_1_svc(registro *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
remove_1_svc(registro *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

registro *
busca_1_svc(char **argp, struct svc_req *rqstp)
{
	static registro  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
altera_1_svc(struct registro *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}
