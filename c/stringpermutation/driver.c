#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int 
main(int argc, char *argv[])
{
	char string[] = "AZzaCaeAG";
	const int length = strlen(string);
	int countlower[26], countupper[26];
	int count[length];
	int count_unique = 0;
	char *unique_chars = NULL;
	int *count_chars = NULL;
	int i, j;
	
	memset(countlower, 0, sizeof(countlower));
	memset(countupper, 0, sizeof(countupper));
	for (i = 0; i < length; i++) {
		if (islower(string[i])) {
			printf("Lower: %c\n", string[i]);
			if (!countlower[string[i] - 'a'])
				count_unique++;
			countlower[string[i] - 'a']++;
		} else {
			printf("Upper: %c\n", string[i]);
			if (!countupper[string[i] - 'A'])
				count_unique++;
			countupper[string[i] - 'A']++; 
		}
	}
	for (i = 0; i < length; i++) {
		if (islower(string[i])) {
			count[i] = countlower[string[i] - 'a'];
			countlower[string[i] - 'a'] = 0;
		} else {
			count[i] = countupper[string[i] - 'A'];
			countupper[string[i] - 'A'] = 0;
		}
	}
	for (i = 0; i < 26; i++)
		printf("%d\t%d\n", countlower[i], countupper[i]);
	printf("\n");
	printf("Unique characters : %d\n", count_unique);
	j = 0;
	unique_chars = (char *) calloc(count_unique, sizeof(char) * count_unique);
	count_chars = (int *) calloc(count_unique, sizeof(int) * count_unique);
	for (i = 0; i < length; i++) {
		printf("%d\t", count[i]);
		if (count[i]) {
			unique_chars[j] = string[i];
			count_chars[j] = count[i];
			j++;
		}
	}
	printf("\n");	
	for (i = 0; i < count_unique; i++) 
		printf("%c\t%d\n", unique_chars[i], count_chars[i]);
	free(unique_chars);
	free(count_chars);

	return 0;
}
