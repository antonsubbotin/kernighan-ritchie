#include <stdio.h>

#define TAB_WIDTH	8

int main()
{
	int pos_in = 0;
	int pos_out = 0;
	int current_tab, i;
	char c;
	int blanks = 0;

	while ((c=getchar()) != EOF) {
		if (c != '\t' && c !=' ') {
			/* non-blank */
			if (blanks) {
				/* blanks substring ended, entab from pos_out to pos_in */

				for (i = 0; i < (pos_in/TAB_WIDTH - pos_out/TAB_WIDTH); ++i)
					putchar('\t');
				for (i = 0; i < pos_in % TAB_WIDTH; ++i)
					putchar(' ');
				blanks = 0;
				pos_out = pos_in;
			}

			putchar(c);
			pos_in += 1;
			pos_out += 1;
		} 
		if (c == '\t') {
			current_tab = TAB_WIDTH - pos_in % TAB_WIDTH;
			pos_in += current_tab;
			blanks += current_tab;
		}
		if (c == ' ') {
			pos_in += 1;
			blanks += 1;
		}
		if (c == '\n') {
			pos_in = pos_out = 0;
		}
	}
	return 0;
}
