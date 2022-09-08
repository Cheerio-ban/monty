
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int a = 10;
char **get_tokens(void)
{
	char **tokens, **q;
	char *p = NULL;
	size_t n = 0;
	ssize_t s ;
	char *token;
	int i = 0;
	int no = 4;

	s = getline(&p, &n,stdin);
	tokens = malloc(sizeof(char *) * no);
	if (tokens == NULL)
	{
		perror("failed to make tokens");
	}

	token = strtok(p, " \n");
	if (!token)
	{
		perror("invalid");
		exit(98);
	}
	tokens[i] = token;

	

	return (tokens);
} 

int main(void)
{
	char **q;
	int b;


	q = get_tokens();


	for (int b = 0; q[b]; b++)
	{
		printf("%s\n%d\n", q[b], a);
	}

	char *r = strtok(NULL, " \n");
	printf("%s\n", r);
	while(r != NULL)
		r = strtok(NULL, " \n");

	/*char *h = "my name";
	char *p = strtok(h, " \n");*/
	/*printf("%s\n", );*/

}
