#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define CHARS_NUM 		0xffu
#define H_SCALE_FACTOR 	3
#define V_SCALE_FACTOR 	.5
#define VH_SPACING		2

#define DRAW_CHAR		'*'
#define SPACE_CHAR		' '

/* Print histograms of frequencies of alphabetic characters */

main()
{
	int 	ccount[CHARS_NUM];	// Array for counts of all characters
	float 	freqs[CHARS_NUM];
	int 	ctotal = 0; // Overall characters count
	int 	cdistinct = 0; 
	char 	c;
	int 	i, j, k, position;
	float 	maxfreq = 0;

	// Initialize the chars count array
	for (i = 0; i < CHARS_NUM; ++i)
		ccount[i] = 0;

	// Count number of occurences of each character in the input, 
	// and total characters
	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			++ctotal;
			++ccount[tolower(c)];
		}
	}

	// Calculate frequencies and print horizontal histograms,
	// Calculate variables for vertical histos
	for (i = 0; i < CHARS_NUM; ++i) {
		if (ccount[i]) {
			freqs[i] = 100 * (float) ccount[i] / ctotal;

			// print a histogram
			j = (int) round(freqs[i] * H_SCALE_FACTOR);
			printf("%c - %5.2f%: ", i, freqs[i]);
			while (j--)
				putchar('_');
			putchar('\n');
			// This is for verticals
			++cdistinct;
			if (freqs[i] > maxfreq)
				maxfreq = freqs[i];
		}
	}

	putchar('\n');

	// Print vertical histograms
	for (i = (int) round(maxfreq * V_SCALE_FACTOR); i; --i) {
		// Print a line
		for (position = 0, j = 0; position < cdistinct; ++position, ++j) {
			// skip non-present chars
			while (!ccount[j])
				++j;
			// Print spacing
			if (position)
				for (k = VH_SPACING; k--; putchar(SPACE_CHAR))
					;
			putchar((int) round(freqs[j] * V_SCALE_FACTOR) >= i ? DRAW_CHAR : SPACE_CHAR);
		}
		putchar('\n');
	}

	putchar('\n');

	for (position = 0, j = 0; position < cdistinct; ++position, ++j) {
		// skip non-present chars
		while (!ccount[j])
			++j;	
		// Print spacing
		if (position)
			for (k = VH_SPACING; k--; putchar(' '))
				;
		putchar(j);
	}
	putchar('\n');

}