
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int a;

char **get_tokens(void)
{
	char **tokens, **q;
	char *p;
	size_t n = 0;
	ssize_t s ;
	char *token;
	int i = 0;
	int no = 4;

	a = 10;
	s = getline(&p, &n,stdin);
	tokens = malloc(sizeof(char *) * no);
	if (tokens == NULL)
	{
		perror("failed to make tokens");
	}

	token = strtok(p, " \n");
	tokens[i] = token;

	while (token != NULL)
	{
		token = strtok(NULL, " \n");
		i++;
		tokens[i] = token;
	}
	i++;
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

}