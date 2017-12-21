#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define CHARS_NUM 	0xffu
#define HISTOGRAM_SCALE_FACTOR 	5

/* Print histograms of frequencies of printable characters */

main()
{
	int ccount[CHARS_NUM];	// Array for counts of all characters
	int ctotal = 0; // Overall characters count
	char c;
	int i, j;
	float freq;

	// Initialize the array
	for (i = 0; i < CHARS_NUM; ++i)
		ccount[i] = 0;

	// Count number of occurences of each character in the input, 
	// and total characters
	while ((c = getchar()) != EOF) {
		if (isprint(c)) {
			++ccount[c];
			++ctotal;
		}
	}

	// printf("total characters: %d\n", ctotal);

	for (i = 0; i < CHARS_NUM; ++i) {
		freq = 100 * (float) ccount[i] / ctotal;
		if (ccount[i]) {
			j = (int) round(freq * HISTOGRAM_SCALE_FACTOR);
			printf("%c - %5.2f%: ", i, freq);
			// printf("%c - %d%: ", i, ccount[i]);
			while (j--)
				putchar('-');
			putchar('\n');
		}
	}
}