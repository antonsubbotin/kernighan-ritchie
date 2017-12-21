#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);

void reverse(char s[]);

/* Reverse input a line at a time */
int main()
{
	char line[MAXLINE];

	while (getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s\n", line);
	}

	return 0;
}


/* getline: read a line into s, return length; without newline char */
int getline(char s[], int lim)
{
	int c, i;
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

/* reverse: reverse the character string s */
void reverse(char s[])
{
	int len, i;
	char c;

	for (len = 0; s[len] != '\0'; ++len)
		;
	for (i = 0; i < len/2; i++) {
		c = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = c;
	}
}