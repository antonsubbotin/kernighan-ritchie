#include <stdio.h>

#define TAB_WIDTH	8

int main()
{
	int col = 0;
	char c;
	int i;

	while ((c=getchar()) != EOF) {
		if (c == '\t') {
			/* add blanks as needed */
			do
				putchar(' ');
			while (++col % TAB_WIDTH != 0);
		} else {
			putchar(c);
			++col;
		}
		if (c == '\n')
			col = 0;
	}

	return 0;
}
