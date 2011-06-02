#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"
#include "libpq-fe.h"

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
  const char *conninfo;
  PGconn     *conn;
  PGresult   *res;
  const char *insert_query = malloc(sizeof(registro));
  sprintf(insert_query,"INSERT INTO registros VALUES('%s', '%s', '%s','%s');",argp->nome,argp->email,argp->telefone_celular,argp->telefone_residencial);

  /*
   * If the user supplies a parameter on the command line, use it as the
   * conninfo string; otherwise default to setting dbname=postgres and using
   * environment variables or defaults for all other connection parameters.
   */
  conninfo = "user = 'guilherme' dbname = 'agenda_telefonica'";
  /* Make a connection to the database */
  conn = PQconnectdb(conninfo);

  /* Check to see that the backend connection was successfully made */
  if (PQstatus(conn) != CONNECTION_OK)
  {
      fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
      result = 2;  //banco nao esta ON.
      return &result;
  }

  res = PQexec(conn, insert_query);
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
      fprintf(stderr, "INSERT command failed: %s", PQerrorMessage(conn));
      result = 0;
      return &result;
  }

  /*
   * should PQclear PGresult whenever it is no longer needed to avoid memory
   * leaks
   */
  PQclear(res);

  /* close the connection to the database and cleanup */
  PQfinish(conn);
  result = 1;
	return &result;
}

int *
remove_1_svc(registro *argp, struct svc_req *rqstp)
{
	static int  result;
  const char *conninfo;
  PGconn     *conn;
  PGresult   *res;
  const char *remove_query = malloc(sizeof(registro));
  sprintf(remove_query,"DELETE FROM registros WHERE email = '%s';",argp->email);

  /*
   * If the user supplies a parameter on the command line, use it as the
   * conninfo string; otherwise default to setting dbname=postgres and using
   * environment variables or defaults for all other connection parameters.
   */
  conninfo = "user = 'guilherme' dbname = 'agenda_telefonica'";
  /* Make a connection to the database */
  conn = PQconnectdb(conninfo);

  /* Check to see that the backend connection was successfully made */
  if (PQstatus(conn) != CONNECTION_OK)
  {
      fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
      result = 2;  //banco nao esta ON.
      return &result;
  }

  res = PQexec(conn, remove_query);
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
      fprintf(stderr, "REMOVE command failed: %s", PQerrorMessage(conn));
      result = 0;
      return &result;
  }

  /*
   * should PQclear PGresult whenever it is no longer needed to avoid memory
   * leaks
   */
  PQclear(res);

  /* close the connection to the database and cleanup */
  PQfinish(conn);
  result = 1;
	return &result;}

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
