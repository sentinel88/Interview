#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _INIT_SIZE 1000
#define ALPHABET_SIZE 256

/* Brute force approach is to allocate a static character array in order to accept a user input in the form of a string. A better approach would be to make a dynamic memory allocation for a fixed size and then resize it once it reaches the limit. In such a case, the string from the user will have to be accepted by writing a while loop and reading a single character everytime and making a check for the limit */

static int 
pattern_match (char *str, char *str1)
{
	int len1, len2;
	char *ptr = NULL, *ptr1 = NULL;
	int j = 0;

	ptr = str;
	ptr1 = str1;
	len1 = strlen(str);
	len2 = strlen(str1);
	if (len2 > len1) {
		printf("\nThe given pattern is invalid for matching\n");
		return -1;
	}	
	printf("\n");
	while (*ptr) {
		j = 0;
		while (*ptr && *ptr1) {
			printf("%c:%c\t", *ptr, *ptr1);
			if (*ptr != *ptr1)
				break;
			j++;
			ptr++;
			ptr1++;
		}
		printf("\n");
		df (*ptr1 == '\0') {
			printf("\nPattern match successful\n");
			break;
		}
		if (!j) {
			ptr++;
		}
		ptr1 = str1;
	}
	if (*ptr1 != '\0') {
		printf("\nPattern match unsuccessful\n");
		return -1;
	}	

	return 0;
}


static int 
pattern_match_horspool (char *str, char *pat)
{
	int len1, len2;
	int table[ALPHABET_SIZE];
	char *ptr = NULL, *ptr1 = NULL;
	int j = 0;
	int i;

	ptr = str;
	ptr1 = pat;
	len1 = strlen(str);
	len2 = strlen(pat);
	if (len2 > len1) {
		printf("\nThe given pattern is invalid for matching\n");
		return -1;
	}	
	for (i = 0; i < ALPHABET_SIZE; i++) {
		table[i] = len2;
	}
	printf("\n");
	for (i = 0; i < (len2 - 1); i++) {
		table[pat[i]] = len2 - i - 1;
	}
	printf("\n");
	for (i = 0; i < ALPHABET_SIZE; i++) {
		printf("%d \t", table[i]);
	}
	i = 0;
	printf("\n");
	while (i <= (len1 - len2)) {
		printf("i: %d\n", i);
		j = len2 - 1;
		while (j >= 0) {
			printf("%c:%c\t", ptr[j], ptr1[j]);	
			//getchar();
			if (ptr[j] != ptr1[j])
				break;
			j--;
			//getchar();
		}
		printf("\n");
		if (j < 0) {
			printf("\nPattern match found at index: %d\n", i);
			ptr++;
			i++;
			continue;
		}
		printf("%c ", ptr[len2 - 1]);
		printf("%d", table[ptr[len2 - 1]]);
		i += table[ptr[len2 - 1]];
		ptr = ptr + table[ptr[len2 - 1]];
	}
	printf("\n");

	return 0;
}


int main (int argc, char *argv[])
{
	char str1[_INIT_SIZE];
	char str[] = "How to edtend a class through edtend inheritance";
	int ret_val = 0;

	memset(str1, 0, _INIT_SIZE);	
	printf("\nThe input string is: %s\n", str);
	printf("\nEnter the test string to perform pattern match\n");
	fgets(str1, _INIT_SIZE, stdin);
	str1[strlen(str1) - 1] = '\0';   // fgets already stores a terminating NULL byte after the last character in the buffer
	printf("\nThe test string to match is: %s", str1);
	ret_val = pattern_match_horspool(str, str1);
	//ret_val = pattern_match(str, str1);

	return 0;
}
