/* K */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL 1002
#define ABC 26

int main()
{
	char * normal = (char *)malloc(sizeof(char) *INITIAL);
	char * sticky = (char *)malloc(sizeof(char) *INITIAL);
	fgets(normal, INITIAL, stdin);
	fgets(sticky, INITIAL, stdin);
	char * goThrough = normal;
	char * stickyThrough = sticky;
	char * chars = (char *)malloc(sizeof(char) * (ABC + 1));
	memset(chars, 0, sizeof(char) * (ABC + 1));
	while (*goThrough){
		while (*goThrough != *stickyThrough)
		{
			if (*stickyThrough == ' ')
				chars[ABC] = 1;
			else
				chars[*stickyThrough - 'a'] = 1;
			stickyThrough++;
		}
		goThrough++;
		stickyThrough++;
	}
	for (int i = 0; i < ABC; i++)
	{
		if (chars[i])
			printf("%c",  'a' + i);
	}
	if (chars[ABC])
			putc(' ', stdout);
	free(chars);
	free(normal);
	free(sticky);
	return 0;
}