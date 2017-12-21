#include <stdio.h>

#define	MAXLINE 	3000

int getcroppedline(char line[], int maxline);
// int croptail(char to[], char from[]);

int main ()
{
	char line[MAXLINE];
	int len;

	while ((len = getcroppedline(line, MAXLINE)) > 0)
		if (len > 1)
			printf("%d: %s", len, line);

	return 0;
}

int getcroppedline(char line[], int lim)
{
	char c;
	int i;
	int end = 0;

	for (i = 0; (c=getchar())!=EOF && i < lim-1 && c!='\n'; ++i) {
		line[i] = c;
		if (c != '\t' && c != ' ')
			end = i;
	}
	// rewind to the last non-blank
	i = end;

	if (c == '\n')
		line[++i] = c;

	line[i+1] = '\0';
	return i;
}
